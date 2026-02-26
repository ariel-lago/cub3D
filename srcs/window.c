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

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

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

static void	create_win(t_win *window)
{
	window->width = WIN_WIDTH;
	window->height = WIN_HEIGHT;
	window->title = "cub3D";
	window->mlx = NULL;
	window->win = NULL;
}

int	init_window(t_win *window)
{
	create_win(window);

	window->mlx = mlx_init();
	if (!window->mlx)
		return(error("Error initializing MinilibX"), FAILURE);

	window->win = mlx_new_window(window->mlx,
					window->width,
					window->height,
					window->title);
	if (!window->win)
		return(error("Error creating Window"), FAILURE);
    return (SUCCESS);
}

int	close_window(t_game *game)
{
    ft_printf("\n===GAME OVER===\n");
    ft_printf("Final position: (%d, %d)\n", (int)game->player.pos_x, (int)game->player.pos_y);
    printf("Final direction: (%.2f, %.2f)\n", game->player.dir_x, game->player.dir_y);
	mlx_destroy_window(game->window.mlx, game->window.win);
	exit(0);
	return (0);
}

