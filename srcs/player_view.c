/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:29:01 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/18 14:29:59 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	toggle_minimap(t_game *game)
{
	if (game->mm_size == 8)
		game->mm_size = 4;
	else
		game->mm_size = 8;
	game->m_pressed = false;
}

/* Rotates a vector by a given angle (+ = right, - = left)
    1. Stores original x-value
    2. Applies 2D rotation logic:
        new_x = (stay * old_x) - (swap * old_y)
        new_y = (swap * old_x) + (stay * old_y)
        -> stay = cos(angle), swap = sin(angle)
*/
t_vector	rotate_vector(t_vector vector, double angle)
{
	t_vector	result;
	double		old_x;

	old_x = vector.x;
	result.x = vector.x * cos(angle) - vector.y * sin(angle);
	result.y = old_x * sin(angle) + vector.y * cos(angle);
	return (result);
}

/* Rotates the player's direction and plane vectors
   Calls rotate function on both vectors to keep camera perpendicular
*/
void	rotate_player(t_player *player, double angle)
{
	player->dir = rotate_vector(player->dir, angle);
	player->plane = rotate_vector(player->plane, angle);
}

/* sets the plane vector:
    1. sets player FOV (degrees) and converts into radians
    2. calculates each side's plane length based on FOV
        This determines how wide camera sees.
    3. Sets plane vector perpendicular to dir
        (rotated 90 degrees to the right of dir)
        and scales it by the planes length to match FOV.
   Call this for changing/initializing FOV.
*/
void	set_player_plane(t_game *game, double fov_degree)
{
	double	fov_rad;
	double	plane_len;

	game->player.fov = fov_degree;
	fov_rad = game->player.fov * PI / 180.0;
	plane_len = tan(fov_rad / 2.0);
	game->player.plane.x = -game->player.dir.y * plane_len;
	game->player.plane.y = game->player.dir.x * plane_len;
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
       NW         PLANE_LEN = 0.65        NE
  (-0.7, -0.7)  . - - - - - - - - - . (0.7, -0.7)
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
