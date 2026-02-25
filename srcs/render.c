/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:48:21 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/24 17:06:25 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define SIZE 	8
#define WALL	0x444444
#define FLOOR	0xCCCCCC
#define PLAYER	0xFF444
#define EMPTY	0x111111

void create_canvas(t_game *game)
{
	game->canvas.img = mlx_new_image(game->window.mlx, WIN_WIDTH, WIN_HEIGHT);
    game->canvas.addr = mlx_get_data_addr(game->canvas.img,
                                          &game->canvas.bpp,
                                          &game->canvas.line_len,
                                          &game->canvas.endian);
}

void	render(t_game *game)
{
	create_canvas(game);
	draw_window(game);
	render_2d_map(game);
	mlx_put_image_to_window(game->window.mlx, game->window.win, 
                           game->canvas.img, 0, 0);
}

static void	pixel(t_game *game, int col, int row, int color)
{
	int	x;
	int	y;
	int	screen_y;
	int	screen_x;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			screen_x = col * SIZE + x;
			screen_y = row * SIZE + y;
			put_pixel(&game->canvas, screen_x, screen_y, color);
			x++;
		}
		y++;
	}
}

void	render_2d_map(t_game *game)
{
	int		x;
	int		y;
	char	c;
	int		color;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			c = game->map.map[y][x];
			if (c == '1')
				color = WALL;
			else if (c == '0')
				color = FLOOR;
			else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				color = PLAYER;
			else
				color = EMPTY;
			pixel(game, x, y, color);
			x++;
		}
		y++;
	}
}
