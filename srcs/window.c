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

void put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;
    
    // Calculate WHERE in memory this pixel lives
    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    
    // Write the color THERE
    *(unsigned int*)dst = color;
}

void draw_window(t_game *game)
{
	int	x;
	int	y;
    // Create image using game's mlx
    game->canvas.img = mlx_new_image(game->window.mlx, WIN_WIDTH, WIN_HEIGHT);
    game->canvas.addr = mlx_get_data_addr(game->canvas.img,
                                          &game->canvas.bpp,
                                          &game->canvas.line_len,
                                          &game->canvas.endian);
    
    // Draw something
    y = 0;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            if (y < WIN_HEIGHT / 2)
                // Top half - sky blue
                put_pixel(&game->canvas, x, y, 0x87CEEB);
            else
                // Bottom half - brown floor
                put_pixel(&game->canvas, x, y, 0x8B4513);
            x++;
        }
        y++;
    } 
    // Put image to window
    mlx_put_image_to_window(game->window.mlx, game->window.win, 
                           game->canvas.img, 0, 0);
}

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

