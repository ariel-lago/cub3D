/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:53:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/18 15:23:13 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  Updates a given position
    Checks if the new position is out of bounds
    or blocked by walls, if not = move
*/
static void	update_pos(t_player *player, t_vector new, t_map *map)
{
	if (new.x < 0 || new.x >= map->map_width || \
		new.y < 0 || new.y >= map->map_height || \
	map->map[(int)new.y][(int)new.x] != '0')
		return ;
	player->pos.x = new.x;
	player->pos.y = new.y;
}

/*  Moves the player forward relative to camera direction
    Uses direction plane
    multiplied by fields per frame (move_speed)
    to calculate the new position.
*/
void	go_straight(t_player *player, t_map *map)
{
	t_vector	new;

	new.x = player->pos.x + player->dir.x * player->move_speed;
	new.y = player->pos.y + player->dir.y * player->move_speed;
	update_pos(player, new, map);
}

/*  Moves the player backwards relative to camera direction
    Uses -direction plane
    multiplied by fields per frame (move_speed)
    to calculate the new position.
*/
void	go_back(t_player *player, t_map *map)
{
	t_vector	new;

	new.x = player->pos.x - player->dir.x * player->move_speed;
	new.y = player->pos.y - player->dir.y * player->move_speed;
	update_pos(player, new, map);
}

/*  Moves the player left relative to camera direction
    Uses -perpendicular plane (90° to the right)
    multiplied by fields per frame (move_speed)
    to calculate the new position.
*/
void	go_left(t_player *player, t_map *map)
{
	t_vector	new;

	new.x = player->pos.x - player->plane.x * player->move_speed;
	new.y = player->pos.y - player->plane.y * player->move_speed;
	update_pos(player, new, map);
}

/*  Moves the player right relative to camera direction
    Uses perpendicular plane (90° to the right)
    multiplied by fields per frame (move_speed)
    to calculate the new position.
*/
void	go_right(t_player *player, t_map *map)
{
	t_vector	new;

	new.x = player->pos.x + player->plane.x * player->move_speed;
	new.y = player->pos.y + player->plane.y * player->move_speed;
	update_pos(player, new, map);
}
