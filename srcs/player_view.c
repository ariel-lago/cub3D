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
    - sin = opposite / hypotenuse = height/length
    - cos = adjacent / hypotenuse = width/length
    - tan = opposite / adjacent = height/width
*/

/* Rotates a vector by a given angle (+ = right, - = left)
    1. Stores original x-value
    2. Applies 2D rotation logic:
        new_x = (stay * old_x) - (swap * old_y)
        new_y = (swap * old_x) + (stay * old_y)
        -> stay = cos(angle), swap = sin(angle)
*/
t_vector rotate_vector(t_vector vector, double angle)
{
    t_vector result;
    double old_x;
    
    old_x = vector.x;
    
    result.x = vector.x * cos(angle) - vector.y * sin(angle);
    result.y = old_x * sin(angle) + vector.y * cos(angle);
    
    return (result);
}

/* Rotates the player's direction and plane vectors
   Calls rotate function on both vectors to keep camera perpendicular
*/
void rotate_player(t_player *player, double angle)
{
    player->dir = rotate_vector(player->dir, angle);
    player->plane = rotate_vector(player->plane, angle);
}

/* Examples: 

    1. Rotate from South to West (90 degrees)

    cos(90°) = 0 (0% stays)
    sin(90°) = 1 (100% slides)

    OLD DIR = (0, 1) -> SOUTH
    old x = 0
    x = x * cos(90) - y * sin(90)
->  0 * 0 - 1 * 1 = -1 
    y = old x * sin(90) + y * cos(90)
->  0 * 1 + 0 * 0 = 0
    NEW DIR = (-1, 0) -> WEST

    OLD PLANE = (-0.65, 0) -> WEST 
    old x = -0.65
    x = x * cos(90) - y * sin(90)
->  - 0.65 * 0 - 0 * 1  = 0
    y = old x * sin(90) + y * cos(90)
->  - 0.65 * 1 + 0 * 0 = -0.65
    NEW PLANE = (0, -0.65) -> NORTH

    2. Rotate from South to Southwest (45 degrees)

    cos(45°) = 0.71 (71% stays)
    sin(45°) = 0.71 (71% slides)

    OLD DIR = (0, 1) -> SOUTH
    old x = 0

    x = x * cos(45) - y * sin(45)
->  0 * 0.71 - 1 * 0.71
    x = 0 - 0.71 = -0.71

    y = old x * sin(45) + y * cos(45)
->  0 * 0.71 + 1 * 0.71
    y = 0 + 0.71 = 0.71

    NEW DIR = (-0.71, 0.71) -> SOUTHWEST ✓

    OLD PLANE = (-0.65, 0) -> WEST
    old x = -0.65

    x = x * cos(45) - y * sin(45)
->  -0.65 * 0.71 - 0 * 0.71
    x = -0.46 - 0 = -0.46

    y = old x * sin(45) + y * cos(45)
->  -0.65 * 0.71 + 0 * 0.71
    y = -0.46 + 0 = -0.46

    NEW PLANE = (-0.46, -0.46) -> NORTHWEST (perpendicular to SW)

    3. Rotate from South to South-Southwest (30 degrees) with FOV 90
    
    cos(30°) = 0.87 (87% stays)
    sin(30°) = 0.50 (50% slides)

    OLD DIR = (0, 1) -> SOUTH
    old x = 0

    DIRECTION ROTATION:
    x = x * cos(30) - y * sin(30)
->  0 * 0.87 - 1 * 0.50
    x = 0 - 0.50 = -0.50

    y = old x * sin(30) + y * cos(30)
->  0 * 0.50 + 1 * 0.87
    y = 0 + 0.87 = 0.87

    NEW DIR = (-0.50, 0.87) -> 30° WEST OF SOUTH

    OLD PLANE for FOV 90° = (-1.0, 0) -> WEST (since plane_len = 1.0)
    old x = -1.0

    PLANE ROTATION:
    x = x * cos(30) - y * sin(30)
->  -1.0 * 0.87 - 0 * 0.50
    x = -0.87 - 0 = -0.87

    y = old x * sin(30) + y * cos(30)
->  -1.0 * 0.50 + 0 * 0.87
    y = -0.50 + 0 = -0.50

    NEW PLANE = (-0.87, -0.50) -> points NORTH-NORTHWEST
*/

/* sets the plane vector:
    1. sets player FOV (degrees) and converts into radians
    2. calculates each side's plane length based on FOV
        This determines how wide camera sees.
    3. Sets plane vector perpendicular to dir
        (rotated 90 degrees to the right of dir)
        and scales it by the planes length to match FOV.
   Call this for changing/initializing FOV.
*/
void    set_player_plane(t_game *game, double fov_degree)
{
    double  fov_rad;
    double  plane_len;

    game->player.fov = fov_degree;
    fov_rad = game->player.fov * PI / 180.0;
    plane_len = tan(fov_rad/ 2.0);

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
