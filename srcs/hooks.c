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
		close_window(game);
	if (keycode == KEY_LEFT)
		game->keys.left = true;
	if (keycode == KEY_RIGHT)
		game->keys.right = true;
	if (keycode >= 0 && keycode < 256)
		game->keys.pressed[keycode] = true;
	
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
