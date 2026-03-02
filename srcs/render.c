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
#define WALL	0x9999FF
#define FLOOR	0xFF99FF
#define PLAYER	0xFF6666
#define EMPTY	0x66F99F
#define LINE	0x66F99F

void create_canvas(t_game *game)
{
	if (game->canvas.img)
		mlx_destroy_image(game->window.mlx, game->canvas.img);
	game->canvas.img = mlx_new_image(game->window.mlx, WIN_WIDTH, WIN_HEIGHT);
    game->canvas.addr = mlx_get_data_addr(game->canvas.img,
                                          &game->canvas.bpp,
                                          &game->canvas.line_len,
                                          &game->canvas.endian);
}

void	render(t_game *game)
{
	static t_vector	last_pos;
	static t_vector	last_dir;
	static double	last_fov;

	if (last_pos.x != game->player.pos.x || last_pos.y != game->player.pos.y ||
		last_dir.x != game->player.dir.x || last_dir.y != game->player.dir.y ||
		last_fov != game->player.fov)
	{
		create_canvas(game);
		draw_window(game);
		render_2d_map(game);
		mlx_put_image_to_window(game->window.mlx, game->window.win, 
        	                   game->canvas.img, 0, 0);
		last_pos.x = game->player.pos.x;
		last_pos.y = game->player.pos.y;
		last_dir.x = game->player.dir.x;
		last_dir.y = game->player.dir.y;
	}
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

static int	within_bounds(t_game *game)
{
	t_vector	ahead;

	ahead.x = (int)(game->player.pos.x + game->player.dir.x);
	ahead.y = (int)(game->player.pos.y + game->player.dir.y);

	if (ahead.x >= 0 && ahead.x < game->map.map_width &&
		ahead.y >= 0 && ahead.y < game->map.map_height)
		return (true);
	return (false);
}

static void	draw_line(t_game *game, t_vector center, double angle)
{
	t_vector	dot;
	t_vector	edge;
	int	i;

	edge = rotate_vector(game->player.dir, angle);
	i = 1;
    while (i++ <= 10)
    {
        dot.x = center.x + (int)(edge.x * i);
        dot.y = center.y + (int)(edge.y * i);
        if (within_bounds(game))
            put_pixel(&game->canvas, dot.x, dot.y, LINE);
    }
}

static void	draw_dir_2d(t_game *game)
{
	t_vector	center;
	double		half_fov;

	center.x = (int)game->player.pos.x * SIZE + SIZE/2;
	center.y = (int)game->player.pos.y * SIZE + SIZE/2;
	half_fov = (game->player.fov * PI / 180.0) / 2.0;

	draw_line(game, center, 0);
	draw_line(game, center, half_fov);
	draw_line(game, center, -half_fov);
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
			if (x == (int)game->player.pos.x && y == (int)game->player.pos.y)
				color = PLAYER;
			else
			{
				c = game->map.map[y][x];
				if (c == '1')
					color = WALL;
				else if (c == '0')
					color = FLOOR;
				else
					color = EMPTY;
			}
			pixel(game, x, y, color);
			x++;
		}
		y++;
	}
	draw_dir_2d(game);
}
