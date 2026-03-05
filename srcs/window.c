/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:03:36 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/24 17:34:06 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

/* Fills pixel at (x, y) with color
    Offset = (y * bytes per row) + (x * bytes per pixel)
    Added to image buffer start to locate pixel,
    writes all 4 bytes to fill with color
    (works w bpp = 32)
*/
void put_pixel(t_img *img, int x, int y, int color)
{
    char *pixel_data;

    pixel_data = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)pixel_data = color;
}

/* Fills window with (top)half ceiling, (bottom)half floor
    Iterates through every pixel row by row, column by column
    Uses WIN_HEIGHT/2 as dividing line between colors.
*/
void    draw_window(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            if (y < WIN_HEIGHT / 2)
                put_pixel(&game->canvas, x, y, game->map.ceiling_color);
            else
                put_pixel(&game->canvas, x, y, game->map.floor_color);
            x++;
        }
        y++;
    }
}

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
		return(error("MinilibX failed", 1), FAILURE);
	window->win = mlx_new_window(window->mlx,
					window->width,
					window->height,
					window->title);
	if (!window->win)
		return(error("Error creating Window", 1), FAILURE);
    return (SUCCESS);
}

/*  Closes the game window
    mlx_destroy_window() removes the window, frees memory
    mlx_destroy_display() disconnects program from display server
*/
int	close_window(t_game *game)
{
    print_end_stats(game);
    mlx_destroy_window(game->window.mlx, game->window.win);
    mlx_destroy_display(game->window.mlx);
    free(game->window.mlx);
	exit(0);
	return (0);
}
