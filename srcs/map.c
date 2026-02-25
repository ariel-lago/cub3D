/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:07:08 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/24 17:05:45 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Checks that all characters in the map line are the allowed ones (01 NSEW) to identify map lines
*/
static int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr("01 NSEW", line[i]))
			return (FALSE);
		i++;
	}
	return (i > 0);
}

/*
Goes through the .cub file and looks for map lines.
It adds one to the height for each line.
It then calculates the length of the line.
If its wider than the previous ones it sets the width value to this length.
*/
int	get_map_size(char *map_name, int *height, int *width)
{
	char	*line;
	int		fd;
	int		len;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	line = get_next_line(fd);
	while (line && !is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && is_map(line))
	{
		len = ft_strlen(line) - 1;
		if (len > *width)
			*width = len;
		(*height)++;
		free (line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (SUCCESS);
}

/*
It allocates space for the map string array of the number of lines in the map. 
It then reads the .cub file and copies each line into a string in the array.
*/
int	load_map(char *map_name, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	map->map = ft_calloc(map->map_height + 1, sizeof(char *));
	if (!map->map)
		return (close(fd), FAILURE);
	line = get_next_line(fd);
	while (line && !is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	while (i < map->map_height && line && is_map(line))
	{
		map->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free (line);
	close(fd);
	return (SUCCESS);
}
