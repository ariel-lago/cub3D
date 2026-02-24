/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:50:25 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/24 14:49:08 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(&game->window);

	game->keys.pressed[keycode] = true;
	
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	game->keys.pressed[keycode] = false;

	return (0);
}

/*
int	game_loop(t_game *game)
{
	if (game->keys.pressed[KEY_W])
		move_forward(game);
	if (game->keys.pressed[KEY_A])
		move_left(game);
	if (game->keys.pressed[KEY_S])
		move_backward(game);
	if (game->keys.pressed[KEY_D])
		move_right(game);
	if (game->keys.pressed[KEY_LEFT])
		rotate_left(game);
	if (game->keys.pressed[KEY_RIGHT])
		rotate_right(game);

	render(game);
	return (0);
} */

