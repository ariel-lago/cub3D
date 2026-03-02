/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:29:01 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/02 13:33:12 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* trigomitry reminder:
    1. Sides of a triangle:
    - Hypotenuse: opposite of right angle (longest)
    - Opposite: side across chosen angle
    - Adjacent: side that touches chosen angle (not Hypotenuse)
    2. Ratios of sides:
    - sin = opposite / hypotenuse
    - cos = adjacent / hypotenuse
    - tan = opposite / adjacent
*/

/* Rotates the player's direction and plane vectors by a given angle:
    1. Stores original direction and plane x-values
    2. */
void     rotate_player(t_player *player, double angle)
{
    double  old_dir_x;
    double  old_plane_x;

    old_dir_x = player->dir_x;
    old_plane_x = player->plane_x;
    
    player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
    player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);

    player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
    player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);

}
/* sets the plane vector:
    1. sets player FOV (degrees) and converts into radians
    2. calculates half-angle scale 
    3. Sets plane vector perpendicular to dir
        -> turned 
   Call this for changing/initializing FOV.
*/
void    set_player_plane(t_game *game, double fov_degree)
{
    double  fov_rad;
    double  plane_len;

    game->player.fov = fov_degree;
    fov_rad = game->player.fov * M_PI / 180.0;
    plane_len = tan(fov_rad/ 2.0);

    game->player.plane_x = -game->player.dir_y * plane_len;
    game->player.plane_y = game->player.dir_x * plane_len;
}

/* 
EXAMPLE: DIR NORTH, FOV 66°

plane_len = tan(33°) = 0.65;

dir_y     = -1;
dir_x     = 0;

             dir    len
plane_x   = -(-1) * 0.65   = 0.65;
plane_y   = (0)   * 0.65   = 0;

plane vector = (0.65, 0) -> EAST
                         
                        DIR
                       NORTH
                      (0, -1)
                         ^
                         |
       NW        PLANE_LEN = 0.65        NE
  (-0.65, -1)  . - - - - - - - - - . (0.65, -1)
                .       FOV       .  
                 .       |       .
                  .  33° +  33° .  <- DIR_LEN = 1
                   .     |     .       (always)
                    .    |    .
                     .   |   .
               57°    .  |  .     57°
                       . | .            
      PLANE WEST ←────── . ─────→ PLANE EAST
      (-0.65, 0)         ↑        (0.65, 0)
                    PLAYER VIEW
*/
