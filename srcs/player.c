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

//DEBUG -> prints start stats 
static void    print_start_stats(t_game *game)
{
    ft_printf("\n=== START GAME ===\n");
    ft_printf("Initial position: (%d, %d)\n", 
        (int)game->player.pos_x, (int)game->player.pos_y);
    ft_printf("Initial direction: (%d, %d) -> %c\n",
        (int)game->player.dir_x, (int)game->player.dir_y, game->map.player_dir);
    ft_printf("FOV: %f° → %f rad\n", game->player.fov, game->player.fov * M_PI / 180.0);
    ft_printf("Plane scale: %f\n", tan((game->player.fov * M_PI / 180.0) / 2.0));
}

/* sets the plane vector:
    1. converts FOV (degrees) into radians
    2. calculates half-angle scale 
    3. Sets plane vector perpendicular to dir
   Call this after changing FOV or player direction.
*/
void    set_player_plane(t_game *game)
{
    double  fov_rad;
    double  plane_len;

    fov_rad = game->player.fov * M_PI / 180.0;
    plane_len = tan(fov_rad/ 2.0);

    game->player.plane_x = -game->player.dir_y * plane_len;
    game->player.plane_y = game->player.dir_x * plane_len;
}

/* */
static void    init_player_dir(t_game *game)
{
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
    else if (game->map.player_dir == 'E')
    {
        game->player.dir_x = 1;
        game->player.dir_y = 0;
    }
    else if (game->map.player_dir == 'W')
    {
        game->player.dir_x = -1;
        game->player.dir_y = 0;
    }
}

/* initiates player struct 
   - sets player in the middle of tile (+0.5)
   - set direction based on map data
   - sets standart FOV (66°) and speeds
*/
void    init_player(t_game *game)
{
    game->player.pos_x = game->map.player_x + 0.5;
    game->player.pos_y = game->map.player_y + 0.5;

    init_player_dir(game);

    game->player.fov = 66.0;
    game->player.move_speed = 0.025; // -> how many units (fields) per frame
    game->player.rot_speed = 0.01;   // -> how many radians per frame (ca 0.5°)

    set_player_plane(game);

    print_start_stats(game);
}
