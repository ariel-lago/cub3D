/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:40:13 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/09 19:19:12 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_file(char	*map_name)
{
	int	len;

	if (!map_name)
		return (error("Missing map name", 0), FALSE);
	len = ft_strlen(map_name);
	if (len < 4 || ft_strncmp(map_name + len - 4, ".cub", 4) != 0)
		return (error("Map needs .cub extension", 0), FALSE);
	return (TRUE);
}

static int	has_one_player(t_map *map)
{
	int	x;
	int	y;
	int	player;
	int line_len;

	y = 0;
	player = 0;
	while (y < map->map_height)
	{
		x = 0;
		line_len = ft_strlen(map->map[y]);
		while (x < line_len)
		{
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
			|| map->map[y][x] == 'W' || map->map[y][x] == 'E')
				player++;
			x++;
		}
		y++;
	}
	if (player != 1)
		return (FALSE);
	return (TRUE);
}

static int	flood_fill(char	**map, int y, int x, int height)
{
	if (!map)
		return (FAILURE);
	if (y < 0 || y >= height || x < 0 || x >= (int)ft_strlen(map[y]))
		return (FAILURE);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (SUCCESS);
	if (map[y][x] == ' ' || map[y][x] == '\n' || map[y][x] == '\0')
		return (FAILURE);
	map[y][x] = 'X';
	if (flood_fill(map, y + 1, x, height) == FAILURE)
		return (FAILURE);
	if (flood_fill(map, y - 1, x, height) == FAILURE)
		return (FAILURE);
	if (flood_fill(map, y, x + 1, height) == FAILURE)
		return (FAILURE);
	if (flood_fill(map, y, x - 1, height) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	is_surrounded(t_map *map)
{
	int	x;
	int	y;
	int	line_len;

	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		line_len = ft_strlen(map->map_copy[y]);
		while (x < line_len)
		{
			if (ft_strchr("0NSEW", map->map_copy[y][x]))
			{
				if (flood_fill(map->map_copy, y, x, map->map_height) == FAILURE)
					return (FALSE);
			}
			x++;
		}
		y++;
	}

	return (TRUE);
}

int	is_valid_map(t_map *map)
{
    if (has_one_player(map) == FALSE)
        return (FALSE);
    if (is_surrounded(map) == FALSE)
    	return (FALSE);
	else
		return (TRUE);
}
