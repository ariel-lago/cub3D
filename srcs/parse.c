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
	return (NULL);
}

/**
 * Frees a NULL-terminated array of strings created by ft_split
 * 
 * @param split The array to free
 */
void ft_free_split(char **split)
{
    int i;

    // Check if the array exists
    if (!split)
        return;
    
    // Free each individual string
    i = 0;
    while (split[i])
    {
        free(split[i]);  // Free each string
        i++;
    }
    
    // Free the array itself
    free(split);
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
    
    // Split the string by commas
    split = ft_split(rgb_str, ',');
    if (!split || !split[0] || !split[1] || !split[2])
    {
        if (split)
            ft_free_split(split);
        return (-1);
    }
    
    // Convert each part to integer
    r = ft_atoi(split[0]);
    g = ft_atoi(split[1]);
    b = ft_atoi(split[2]);
    
    // Free the split array
    ft_free_split(split);
    
    // Check if values are valid (0-255)
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (-1);
    
    // Combine into a single integer: 0xRRGGBB
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
		return (error("Error\nMissing identifier"), FAILURE);
	return (SUCCESS);
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
		return (FAILURE);
	ft_memset(map, 0, sizeof (t_map));
//	map.player_x = get_x_pos(map_name);
//	map.player_y = get_y_pos(map_name);
//	map.player_dir = get_player_dir(map_name);
	if (find_identifiers(fd, map) == FAILURE)
		return (close(fd), FAILURE);
	if (get_map_size(map_name, &map->map_height, &map->map_width) == FAILURE)
		return (close(fd), FAILURE);
	if (load_map(map_name, map) == FAILURE)
		return (close(fd), error("Error\nCould not load map"), FAILURE);
	close(fd);
	return (SUCCESS);
}

