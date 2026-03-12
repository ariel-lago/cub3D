/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:53:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/11 18:38:58 by alago-ga         ###   ########.fr       */
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
	map->map[(int)new.y][(int)new.x] == '1' )
		return ;
	player->pos.x = new.x;
	player->pos.y = new.y;
}

/*  Moves the player forward relative to camera direction
    Uses direction plane
    multiplied by fields per frame (move_speed)
    to calculate the new position.
*/
static void	go_straight(t_player *player, t_map *map)
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
static void	go_back(t_player *player, t_map *map)
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
static void	go_left(t_player *player, t_map *map)
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
static void	go_right(t_player *player, t_map *map)
{
	t_vector	new;

	new.x = player->pos.x + player->plane.x * player->move_speed;
	new.y = player->pos.y + player->plane.y * player->move_speed;
	update_pos(player, new, map);
}

/* checks if any relevant keys were pressed
    and moves player/view accordingly */
int	move_player(t_game *game)
{
	if (game->keys.pressed[KEY_W])
		go_straight(&game->player, &game->map);
	if (game->keys.pressed[KEY_S])
		go_back(&game->player, &game->map);
	if (game->keys.pressed[KEY_A])
		go_left(&game->player, &game->map);
	if (game->keys.pressed[KEY_D])
		go_right(&game->player, &game->map);
	if (game->keys.left)
		rotate_player(&game->player, -game->player.rot_speed);
	if (game->keys.right)
		rotate_player(&game->player, game->player.rot_speed);
	if (game->keys.down && game->player.fov > 30.00)
		set_player_plane(game, game->player.fov - 1.00);
	if (game->keys.up && game->player.fov < 120.00)
		set_player_plane(game, game->player.fov + 1.00);
	return (SUCCESS);
}
