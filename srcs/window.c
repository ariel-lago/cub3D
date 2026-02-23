/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:03:36 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/23 17:49:54 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

static void	setup_win(t_game *game)
{
	game->window.width = WIN_WIDTH;
	game->window.height = WIN_HEIGHT;
	game->window.title = "cub3D";
	game->window.mlx = NULL;
	game->window.win = NULL;
}

void	init_window(t_win *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		error("Error initializing MinilibX");

	window->win = mlx_new_window(window->mlx,
					window->width,
					window->height,
					window->title);
	if (window->win)
		error("Error creating Window");
}

int	close_window(t_win *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
}

