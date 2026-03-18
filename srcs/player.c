/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:53:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/18 15:34:07 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  sets player direction according to map info
    (0, -1) = N, (0, 1) = S, (-1, 0) = W, (1, 0) = E
*/
static void	init_player_dir(t_game *game)
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
   	game->player.move_speed = 0.035; // -> how many units (fields) per frame
	game->player.rot_speed = 0.01;   // -> how many radians per frame (ca 0.5°)
*/
void	init_player(t_game *game)
{
	game->player.pos.x = game->map.player_x + 0.5;
	game->player.pos.y = game->map.player_y + 0.5;
	init_player_dir(game);
	game->player.fov = 66.0;
	game->player.move_speed = 0.035;
	game->player.rot_speed = 0.01;
	set_player_plane(game, game->player.fov);
	print_start_stats(game);
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
	if (game->keys.down && game->player.fov > 45.00)
		set_player_plane(game, game->player.fov - 1.00);
	if (game->keys.up && game->player.fov < 90.00)
		set_player_plane(game, game->player.fov + 1.00);
	if (game->keys.pressed[KEY_M] && game->m_pressed)
		toggle_minimap(game);
	return (SUCCESS);
}
