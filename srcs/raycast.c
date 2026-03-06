/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:50:57 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/04 21:07:22 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
calculates the distance from the camera plane to the wall
sets the size of the wall that will be drawn
sets the draw start and end so the line is in the middle of the horizon.
*/
static void	get_wall_size(t_ray *ray)
{
	if (ray->wall_type == VERTICAL)
	{
		ray->line_height = (int)WIN_HEIGHT / (ray->cross_dist.x - ray->dist.x);
	}
	else
	{
		ray->line_height = (int)WIN_HEIGHT / (ray->cross_dist.y - ray->dist.y);
	}
	ray->draw_start = WIN_HEIGHT / 2 - ray->line_height / 2;
	ray->draw_end = WIN_HEIGHT / 2 + ray->line_height / 2;	
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end > WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT;
}

/*
Checks whether first_dist .x or .y is smaller
Moves to closest one in the direction of step
adds dist.x or dist.y to first_dist .x .y
sets the wall type to 0 for vertical and 1 for horizontal
checks if its a wall (stops if it is or continues otherwise)
*/
static void	dda_loop(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->cross_dist.x < ray->cross_dist.y)
		{
			ray->map_x += ray->step_x;
			ray->cross_dist.x += ray->dist.x;
			ray->wall_type = VERTICAL;
		}
		else
		{
			ray->map_y += ray->step_y;
			ray->cross_dist.y += ray->dist.y;
			ray->wall_type = HORIZONTAL;
		}
		if (game->map.map[ray->map_y][ray->map_x] == '1')
		{
			get_wall_size(ray);
			break ;	
		}
	}
}

/*
Calculates the distance the ray needs to travel to cross a square in x and y.
Sets the map tile where the player is(the pos but as an int so we just have the tile, not the pos in it);
Calculates distance from first square to the next crossing (since player is in center of square)
sets stepx and y so we know whether it has to move in one or another direction in the axis (if raydir is positive it will be +1 andif negative -1)
Calculates the fist distance from the player position to the end of the tile:
for this we see how far the player is from the tile wall and multiply it by the full distance.
*/
static void	init_dda(t_game *game, t_ray *ray)
{
	ray->dist.x = fabs(1.0/ray->raydir.x);
	ray->dist.y = fabs(1.0/ray->raydir.y);
	ray->map_x = (int)game->player.pos.x;
	ray->map_y = (int)game->player.pos.y;
	if (ray->raydir.x < 0)
	{
		ray->step_x = -1;
		ray->cross_dist.x = (game->player.pos.x - ray->map_x) * ray->dist.x;
	}
	else
	{
		ray->cross_dist.x = (ray->map_x + 1.0 - game->player.pos.x) * ray->dist.x;
		ray->step_x = 1;
	}
	if (ray->raydir.y < 0)
	{
		ray->step_y = -1;
		ray->cross_dist.y = (game->player.pos.y - ray->map_y) * ray->dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->cross_dist.y = (ray->map_y + 1.0 - game->player.pos.y) * ray->dist.y;
	}
	dda_loop(game, ray);
}

/*
draws a column of wall size for each ray casted
*/
void	draw_column(t_game *game, int x)
{
	int	y;
	int	color;

	y = game->ray.draw_start;
	if (game->ray.wall_type == HORIZONTAL)
		color = 0xDF66FF;
	else
		color = 0xFF66DF;
	while (y <= game->ray.draw_end)
	{
		put_pixel(&game->canvas, x, y, color);
		y++;
	}
}

/*
for every column of win width we cast a ray till the next wall
 We set each column to a position in the camera plane (-1.0 to +1.0)
 cam = 0 means it looks straight where the player looks
 cam = 1 means ray leans all the way to the right edge
 cam = -1 means ray leans to the left fully
 we initialise the data needed for calculating distance to wall
 we draw the column for the 3d simmulation
*/
void	cast_rays(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->ray.cam = 2 * x / (double)WIN_WIDTH - 1;
		game->ray.raydir.x = game->player.dir.x + game->player.plane.x * game->ray.cam;
		game->ray.raydir.y = game->player.dir.y + game->player.plane.y * game->ray.cam;
		init_dda(game, &game->ray);
		draw_column(game, x);
		x++;
	}
}
