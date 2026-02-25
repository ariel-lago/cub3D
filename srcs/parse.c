/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:00:37 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/23 19:51:17 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Gets sent the line with the identifier and returns its path/color values.
Increases identifiers by one if it's found the info.
(note: should I add an is space function or do we accept the subjet means a normal ' ' space?)
*/
static char	*get_info(char *line, int *identifiers)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[i] == ' ')
		i++;
	ret = ft_strdup(&line[i]);
	if (ret && (ret[ft_strlen(ret) - 1] == '\n'))
	{
		ret[ft_strlen(ret) - 1] = '\0';
		*identifiers = *identifiers + 1;
		return (ret);
	}
	return (error("Identifier is missing information", 0), NULL);
}

/**
 * Converts a string like "220,100,0" into an integer color 0xDC6400
 * Returns -1 on error
 */
static int parse_rgb(char *rgb_str)
{
    char    **split;
    int     r;
    int     g;
    int     b;
    int     color;
    
    if (!rgb_str)
        return (-1);
    
    split = ft_split(rgb_str, ',');
    if (!split || !split[0] || !split[1] || !split[2])
    {
        if (split)
            free_array(split);
        return (-1);
    }

    r = ft_atoi(split[0]);
    g = ft_atoi(split[1]);
    b = ft_atoi(split[2]);

    free_array(split);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (-1);

    color = (r << 16) | (g << 8) | b;
    
    return (color);
}

/*
Reads the file line by line and searches for identifiers in each line. 
If it finds aan identifier it sends it to get info so assign its value to the struct
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
		if (ft_strncmp(line,"NO ", 3) == 0 && !map->walls[0])
			map->walls[0] = get_info(&line[3], &identifiers);
		else if (ft_strncmp(line,"SO ", 3) == 0 && !map->walls[1])
			map->walls[1] = get_info(&line[3], &identifiers);
		else if (ft_strncmp(line,"WE ", 3) == 0 && !map->walls[2])
			map->walls[2] = get_info(&line[3], &identifiers);
		else if (ft_strncmp(line,"EA ", 3) == 0 && !map->walls[3])
			map->walls[3] = get_info(&line[3], &identifiers);
		else if (ft_strncmp(line,"F ", 2) == 0 && !map->floor_color)
			map->floor_color = parse_rgb(get_info(&line[2], &identifiers));
		else if (ft_strncmp(line,"C ", 2) == 0 && !map->ceiling_color)
			map->ceiling_color = parse_rgb(get_info(&line[2], &identifiers));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (identifiers != 6)
		return (error("Missing identifier", 0), FAILURE);
	return (SUCCESS);
}

int get_player_start(t_map *map)
{
    int     row;
    int     col;
    char    c;

    if (!map || !map->map)
        return (FAILURE);
    row = 0;
    while (row < map->map_height)
    {
        col = 0;
        while (col < map->map_width)
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
	if (get_player_start(map) == FAILURE)
		return (error("Player not found", 0), FAILURE);
	printf("player pos_x: %d\n", map->player_x);
	printf("player pos_y:%d\n", map->player_y);
	printf("player start direction: %c\n", map->player_dir);
	close(fd);
	return (SUCCESS);
}

