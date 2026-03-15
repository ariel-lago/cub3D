/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:40:13 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/15 18:29:21 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_file(char	*file_name, char *type, char *extension)
{
	int	len;
	int	fd;

	if (!file_name || file_name[0] == '\0')
		return (ft_putstr_fd(type, 2), error("Missing file name", 0), FALSE);
	len = ft_strlen(file_name);
	if (len < 4 || ft_strncmp(file_name + len - 4, extension, 4) != 0)
		return (ft_putstr_fd(type, 2), error("Missing file extension", 0), FALSE);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return(ft_putstr_fd(type, 2), error("Cannot open file", 0),FALSE);
	close (fd);
	return (TRUE);
}

int	valid_identifiers(t_map *map, int identifiers)
{
	int	i;

	if (identifiers != 6)
		return (error("Missing texture or color", 0), FALSE);
	i = 0;	
	while (i < 4)
	{
		if (!is_valid_file(map->walls[i], "Texture: ", ".xpm"))
			return (FALSE);
		i++;
	}
	if (map->ceiling_color == -1 || map->floor_color == -1)
		return (error("Invalid floor/ceiling color", 0), FALSE);
	return (TRUE);
}

static int	has_one_player(t_map *map)
{
	int	x;
	int	y;
	int	player;
	int	line_len;

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
		return (error("Map needs one player", 0), FALSE);
	if (is_surrounded(map) == FALSE)
		return (error("Map isn't surrounded by walls", 0), FALSE);
	else
		return (TRUE);
}
