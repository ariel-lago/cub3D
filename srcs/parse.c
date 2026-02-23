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

//looks for the identifier and returns the path/color values attached
//note: should i add an is space function or do we accept the subjet means a normal ' ' space?
static char	*get_info(char *map_name, char *id)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (ft_strncmp(line, id, 2) == SUCCESS)
		{
			while (line[i] == ' ')
				i++;
			return (&line[i]);
		}
		line = get_next_line(fd);
	}
	write (1, "Error\nMissing identifier\n", 25);
	return (NULL);
}

static char	**get_wall_paths(char *map_name, char *wall_paths[])
{
	wall_paths[0] = get_info(map_name, "NO");
	wall_paths[1] = get_info(map_name, "SO");
	wall_paths[2] = get_info(map_name, "WE");
	wall_paths[3] = get_info(map_name, "EA");
	return (wall_paths);
}

int	parse(t_map *map, char *map_name)
{
	map = ft_calloc(1, sizeof (t_map));
	if (!map)
		return (write(2, "malloc failed\n", 14), FAILURE);
//	map.width = get_map_width(map_name);
//	map.length = get_map_length(map_name);
//	map.player_x = get_x_pos(map_name);
//	map.player_y = get_y_pos(map_name);
//	map.player_dir = get_player_dir(map_name);
	get_wall_paths(map_name, map->walls);
	map->floor_color = get_info(map_name, "F ");
	map->ceiling_color = get_info(map_name, "C ");
	return (0);
}

/*
int	parse(t_map *map, char *map_name)
{
	(void)map_name;
	(void)map;

	return (0);
}*/
