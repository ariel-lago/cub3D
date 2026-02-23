/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:00:37 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/23 18:00:09 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_color(char map_name, char c)
{
	int	fd;

	fd = open(file);
}

int	parse(t_map *map, char *map_name)
{
	map = ft_calloc(1, sizeof t_map);
	if (!map)
		return (write(2, "malloc failed\n", 14), FAILURE);
	map.width = get_map_width(map_name);
	map.length = get_map_length(map_name);
	map.player_x = get_x_pos(map_name);
	map.player_y = get_y_pos(map_name);
	map.player_dir = get_player_dir(map_name);
	map.walls = get_wall_paths(map_name);
	map.floor_color = get_color(map_name, f);
	map.ceiling_color = get_color(map_name, c);
	return (0);
}
