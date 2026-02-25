/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:53:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/25 16:53:44 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_player(t_game *game)
{
        game->player.pos_x = game->map.player_x + 0.5;
        game->player.pos_y = game->map.player_y + 0.5;

        if (game->map.player_dir == 'S')
        {
            game->player.dir_x = 0;
            game->player.dir_y = 1;
        }
        else if (game->map.player_dir == 'N')
        {
            game->player.dir_x = 0;
            game->player.dir_y = -1;
        }
        else if (game->map.player_dir = 'E')
        {
            game->player.dir_x = 1;
            game->player.dir_y = 0;
        }
        else if (game->map.player_dir = 'W')
        {
            game->player.dir_x = -1;
            game->player.dir_y = 0;
        }

        game->player.plane_x = game->player.dir_y * 0.66;
        game->player.plane_y = game->player.dir_x * 0.66;
        game->player.move_speed = 0.05;
        game->player.rot_speed = 0.03;
}