/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:00:37 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/12 15:42:52 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Gets sent the line with the identifier and returns its path/color values.
Increases identifiers by one if it's found the info.
*/
static char	*get_info(char *line, int *identifiers)
{
	int		i;
	char	*ret;
	size_t	len;

	i = 0;
	while (line[i] == ' ')
		i++;
	ret = ft_strdup(&line[i]);
	if (!ret)
		return (NULL);
	len = ft_strlen(ret);
	if (ret && (ret[len - 1] == '\n'))
		ret[len - 1] = '\0';

	if (ret[0] == '\0')
	{
		free(ret);
		return (error("Identifier is missing information", 0), NULL);
	}
	(*identifiers)++;
	return (ret);
}

static int	is_valid_rgb(t_rgb color)
{
	return (color.r >= 0 && color.r <= 255 && \
			color.g >= 0 && color.g <= 255 && \
			color.b >= 0 && color.b <= 255);
}

int	rgb_to_int(t_rgb color)
{
	return ((color.r << 16) + (color.g << 8) + color.b);
}

/* Converts RGB-string into integer color:
	- splits string by comma into Red, Green & Blue parts
	- converts each part to int using atoi
	- validates each value is within 0-255
	- combines values using bitwise shifts
	-> Red:   shifted left by 16 bits (into byte 2)
    -> Green: shifted left by 8 bits  (into byte 1)
    -> Blue:  no shift                (into byte 0)
 */
static int	parse_rgb(char *rgb_str)
{
	char	**split;
	t_rgb	rgb;
	
    if (!rgb_str)
        return (-1);
    
    split = ft_split(rgb_str, ',');
    if (!split || !split[0] || !split[1] || !split[2])
    {
        if (split)
            free_array((void **)split, 3);
        return (-1);
    }

    rgb.r = ft_atoi(split[0]);
    rgb.g = ft_atoi(split[1]);
    rgb.b = ft_atoi(split[2]);

    free_array((void **)split, 3);
	free(rgb_str);

    if (!is_valid_rgb(rgb))
        return (-1);

    return (rgb_to_int(rgb));
}

/*
Reads the file line by line and searches for identifiers in each line. 
If it finds an identifier it sends it to get info so assign its value to the struct
It counts the identifiers, if there's a missing identifier it returns failure. 
*/
static int	find_identifiers(int fd, t_map *map)
{
	char	*line;
	int		identifiers;

	identifiers = 0;
	line = get_next_line(fd);
	while (line && identifiers < 6)
	{
		if (ft_strncmp(line,"NO ", 3) == 0 && !map->walls[NORTH])
			map->walls[0] = get_info(&line[3], &identifiers);
		else if (ft_strncmp(line,"SO ", 3) == 0 && !map->walls[SOUTH])
			map->walls[1] = get_info(&line[3], &identifiers);
		else if (ft_strncmp(line,"WE ", 3) == 0 && !map->walls[WEST])
			map->walls[2] = get_info(&line[3], &identifiers);
		else if (ft_strncmp(line,"EA ", 3) == 0 && !map->walls[EAST])
			map->walls[3] = get_info(&line[3], &identifiers);
		else if (ft_strncmp(line, "F ", 2) == 0 && !map->floor_color)
			map->floor_color = parse_rgb(get_info(&line[2], &identifiers));
		else if (ft_strncmp(line, "C ", 2) == 0 && !map->ceiling_color)
			map->ceiling_color = parse_rgb(get_info(&line[2], &identifiers));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (identifiers != 6)
		return (error("Missing identifier", 0), FAILURE);
	return (SUCCESS);
}

/* changed to take row_len instead of map_width ->
	map_width might is the longest row, so if current row is shorter,
	we'd read past the end of the string (using map_width)
	-> out of bound memory access. 
*/
int get_player_start(t_map *map)
{
    int     row;
	int		row_len;
    int     col;
    char    c;

    if (!map || !map->map)
        return (FAILURE);
    row = 0;
    while (row < map->map_height)
    {
        col = 0;
		row_len = ft_strlen(map->map[row]);
        while (col < row_len)
        {
            c = map->map[row][col];
            if (c == 'N' || c == 'S' || c =='E' || c == 'W')
            {
                map->player_x = col;
                map->player_y = row;
                map->player_dir = c;
                map->map[row][col] = '0';
                return (SUCCESS);
            }
            col++;
        }
        row++;
    }
    return (FAILURE);
}

/*
Opens the map file, does sets memory to 0 for the map struct.
Looks for identifiers
Finds the max size of the map and loads the map(strdups it into a string array in the struct)
*/
int	parse(t_map *map, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (error("Open() failed", 1), FAILURE);
	ft_memset(map, 0, sizeof (t_map));
	if (find_identifiers(fd, map) == FAILURE)
		return (close(fd), FAILURE);
	if (get_map_size(map_name, &map->map_height, &map->map_width) == FAILURE)
		return (close(fd), FAILURE);
	if (load_map(map_name, map) == FAILURE)
		return (close(fd), FAILURE);
	if (is_valid_map(map) == FALSE)
		return (close(fd), clean_map(map), FAILURE);
	if (get_player_start(map) == FAILURE)
		return (close(fd), clean_map(map), error("Player not found", 1), FAILURE);
	printf("player pos_x: %d\n", map->player_x);
	printf("player pos_y:%d\n", map->player_y);
	printf("player start direction: %c\n", map->player_dir);
	close(fd);
	return (SUCCESS);
}
