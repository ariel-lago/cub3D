/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:03:36 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/12 15:14:45 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

/* Fills the new Window struct with dimensions/title
    and sets missing pointer values to NULL.
*/
static void	create_win(t_win *window)
{
	window->width = WIN_WIDTH;
	window->height = WIN_HEIGHT;
	window->title = "cub3D";
	window->mlx = NULL;
	window->win = NULL;
}

/*  Initiates the program Window
    mlx_init() connects program to display server
    -> returns pointer to graphics session data (void *mlx)
    mlx_new_window() calls underlying graphics framework
    -> returns pointer to window data (void *win)
*/
int	init_window(t_win *window)
{
	create_win(window);

	window->mlx = mlx_init();
	if (!window->mlx)
		return(error("MinilibX failed", 0), FAILURE);
	window->win = mlx_new_window(window->mlx,
					window->width,
					window->height,
					window->title);
	if (!window->win)
		return(error("Error creating Window", 0), FAILURE);
    return (SUCCESS);
}

/*  Closes the game window
    mlx_destroy_window() removes the window, frees memory
    mlx_destroy_display() disconnects program from display server
*/
int	close_window(t_game *game)
{
    print_end_stats(game);
	
	clean_textures(game);
    mlx_destroy_window(game->window.mlx, game->window.win);
    mlx_destroy_display(game->window.mlx);
    free(game->window.mlx);
	clean_map(&game->map);
	exit(0);
	return (0);
}
