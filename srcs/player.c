/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:53:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/27 17:24:42 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  sets player direction according to map info
    (0, -1) = N, (0, 1) = S, (-1, 0) = W, (1, 0) = E
*/
static void    init_player_dir(t_game *game)
{
    if (game->map.player_dir == 'S')
    {
        game->player.dir.x = 0;
        game->player.dir.y = 1;
    }
    else if (game->map.player_dir == 'N')
    {
        game->player.dir.x = 0;
        game->player.dir.y = -1;
    }
    else if (game->map.player_dir == 'E')
    {
        game->player.dir.x = 1;
        game->player.dir.y = 0;
    }
    else if (game->map.player_dir == 'W')
    {
        game->player.dir.x = -1;
        game->player.dir.y = 0;
    }
}

/* initiates player struct 
   - sets player in the middle of tile (+0.5)
   - set direction based on map data
   - sets standart FOV (66°) and speeds
*/
void    init_player(t_game *game)
{
    game->player.pos.x = game->map.player_x + 0.5;
    game->player.pos.y = game->map.player_y + 0.5;

    init_player_dir(game);

    game->player.fov = 66.0;
    game->player.move_speed = 0.035; // -> how many units (fields) per frame
    game->player.rot_speed = 0.01;   // -> how many radians per frame (ca 0.5°)

    set_player_plane(game, game->player.fov);

    print_start_stats(game);
}
