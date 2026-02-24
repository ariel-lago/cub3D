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

#define SIZE 	16
#define WALL	0x444444
#define FLOOR	0xCCCCCC
#define PLAYER	0xFF444
#define EMPTY	0x111111

static void	put_pixel(t_game *game, int col, int row, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			mlx_pixel_put(game->window.mlx, game->window.win, \
				col * SIZE + x, row * SIZE + y, color);
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
			put_pixel(game, x, y, color);
			x++;
		}
		y++;
	}
}
