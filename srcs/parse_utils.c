/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:09:48 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/16 18:54:41 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
int	parse_rgb(char *rgb_str)
{
	char	**split;
	t_rgb	rgb;

	if (!rgb_str)
		return (-1);
	split = ft_split(rgb_str, ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		if (split)
			free_array((void **)split);
		return (free(rgb_str), 1);
	}
	rgb.r = ft_atoi(split[0]);
	rgb.g = ft_atoi(split[1]);
	rgb.b = ft_atoi(split[2]);
	free_array((void **)split);
	free(rgb_str);
	if (!is_valid_rgb(rgb))
		return (-1);
	return (rgb_to_int(rgb));
}

static int	find_player(t_map *map, int col, int row)
{
	char	c;

	c = map->map[row][col];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		map->player_x = col;
		map->player_y = row;
		map->player_dir = c;
		map->map[row][col] = '0';
		return (SUCCESS);
	}
	return (FAILURE);
}

/* changed to take row_len instead of map_width ->
	map_width might is the longest row, so if current row is shorter,
	we'd read past the end of the string (using map_width)
	-> out of bound memory access. 
*/
int	get_player_start(t_map *map)
{
	int		row;
	int		row_len;
	int		col;

	if (!map || !map->map)
		return (FAILURE);
	row = 0;
	while (row < map->map_height)
	{
		col = 0;
		row_len = ft_strlen(map->map[row]);
		while (col < row_len)
		{
			if (find_player(map, col, row) == SUCCESS)
				return (SUCCESS);
			col++;
		}
		row++;
	}
	return (FAILURE);
}
