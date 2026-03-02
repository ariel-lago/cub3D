/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:50:25 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/27 15:16:50 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* */
int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_LEFT)
		game->keys.left = true;
	if (keycode == KEY_RIGHT)
		game->keys.right = true;
	if (keycode >= 0 && keycode < 256)
		game->keys.pressed[keycode] = true;
	if (keycode == MINUS && game->player.fov > 45.00)
	{
		game->player.fov -= 5.0;
		set_player_plane(game);
	}
	if (keycode == PLUS && game->player.fov < 90.00)
	{
		game->player.fov += 5.0;
		set_player_plane(game);
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	
	if (keycode == KEY_LEFT)
		game->keys.left = false;
	if (keycode == KEY_RIGHT)
		game->keys.right = false;
	if (keycode >= 0 && keycode < 256)
		game->keys.pressed[keycode] = false;

	return (0);
}
