/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:03:36 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/23 19:23:50 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

static void	create_win(t_win *window)
{
	window->width = WIN_WIDTH;
	window->height = WIN_HEIGHT;
	window->title = "cub3D";
	window->mlx = NULL;
	window->win = NULL;
}

void	init_window(t_win *window)
{
	create_win(window);

	window->mlx = mlx_init();
	if (!window->mlx)
		error("Error initializing MinilibX");

	window->win = mlx_new_window(window->mlx,
					window->width,
					window->height,
					window->title);
	if (!window->win)
		error("Error creating Window");
}

int	close_window(t_win *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}

