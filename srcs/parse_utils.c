/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:09:48 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/25 17:10:10 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
            c = map->map[row][col]
            if (c == 'N' || c == 'S' || c = 'E' || c == 'W')
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