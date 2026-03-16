/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:54:36 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/16 18:23:33 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 2D Map values
#define SIZE 	8
#define WALL	0x9999FF
#define FLOOR	0xFF99FF
#define PLAYER	0xFF6666
#define EMPTY	0
#define LINE	0x66F99F

/*  Draws a map tile as a colored SIZE*SIZE square.
	Converts grid position (col, row) to pixel coordinates,
	fills it with a given color pixel by pixel.
*/
static void	draw_map_tile(t_game *game, int row, int col, int color)
{
	int	x;
	int	y;
	int	screen_y;
	int	screen_x;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE && color != EMPTY)
		{
			screen_x = col * SIZE + x;
			screen_y = row * SIZE + y;
			put_pixel(&game->canvas, screen_x, screen_y, color);
			x++;
		}
		y++;
	}
}

/*  Checks if the grid cell directly in front of player
	is within map boundaries, prevents out-of-bound rendering.

static int	within_bounds(t_game *game)
{
	t_vector	ahead;

	ahead.x = (int)(game->player.pos.x + game->player.dir.x);
	ahead.y = (int)(game->player.pos.y + game->player.dir.y);
	if (ahead.x >= 0 && ahead.x < game->map.map_width && \
		ahead.y >= 0 && ahead.y < game->map.map_height)
		return (true);
	return (false);
}*/

/*  Draws a line of dots in a given direction from center point.
	Gets the players direction vector from rotate function
	and extends it by 10 dots to create a line.
	Checks if the grid cell directly in front of player
	is within map boundaries, prevents out-of-bound rendering.
*/
static void	draw_line(t_game *game, t_vector center, double angle)
{
	t_vector	dot;
	t_vector	edge;
	int			i;
	t_vector	ahead;

	ahead.x = (int)(game->player.pos.x + game->player.dir.x);
	ahead.y = (int)(game->player.pos.y + game->player.dir.y);
	edge = rotate_vector(game->player.dir, angle);
	i = 1;
	while (i++ <= 10)
	{
		dot.x = center.x + (int)(edge.x * i);
		dot.y = center.y + (int)(edge.y * i);
		if (ahead.x >= 0 && ahead.x < game->map.map_width && \
		ahead.y >= 0 && ahead.y < game->map.map_height)
			put_pixel(&game->canvas, dot.x, dot.y, LINE);
	}
}

/*  Draws the player's direction and FOV borders on minimap.
	Converts player's grid position to pixel coordinates,
	then draws lines at 0, left and right half_fov angles.
	DEG_TO_RAD: ((deg) * PI / 180.0)
*/
static void	draw_dir_2d(t_game *game)
{
	t_vector	center;
	double		half_fov;

	center.x = (int)game->player.pos.x * SIZE + SIZE / 2;
	center.y = (int)game->player.pos.y * SIZE + SIZE / 2;
	half_fov = (game->player.fov * PI / 180) / 2.0;
	draw_line(game, center, 0);
	draw_line(game, center, half_fov);
	draw_line(game, center, -half_fov);
}

void	add_color(t_game *game, int row, int col, int *color)
{
	char	c;

	if (col == (int)game->player.pos.x 
		&& row == (int)game->player.pos.y)
		*color = PLAYER;
	else
	{
		c = game->map.map[row][col];
		if (c == '1')
			*color = WALL;
		else if (c == '0')
			*color = FLOOR;
		else
			*color = EMPTY;
	}
}

/*  Renders a top-down 2D minimap
	Iterates through map grid: draws walls, floors, empty spaces
	and overlays player position and view direction.
*/
void	render_2d_map(t_game *game)
{
	int		row;
	int		col;
	int		row_len;
	int		color;

	row = 0;
	while (row < game->map.map_height)
	{
		col = 0;
		row_len = ft_strlen(game->map.map[row]);
		while (col < row_len)
		{
			add_color(game, row, col, &color);
			draw_map_tile(game, row, col, color);
			col++;
		}
		row++;
	}
	draw_dir_2d(game);
}
