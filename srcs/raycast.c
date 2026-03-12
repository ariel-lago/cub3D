/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:50:57 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/11 17:44:50 by rbestman         ###   ########.fr       */
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
	ray->line_height = (int)WIN_HEIGHT / ray->wall_dist;
	ray->draw_start = WIN_HEIGHT / 2 - ray->line_height / 2;
	ray->draw_end = WIN_HEIGHT / 2 + ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end > WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT;
}

/* Assigns which type of wall the current ray is being casted on.
	depending on step direction.
*/
static int	get_wall_dir(t_ray *ray)
{
	if (ray->cross_dist.x < ray->cross_dist.y)
	{
		if (ray->step_x < 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (ray->step_y < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
}

/*
Checks whether cross_dist .x or .y is smaller
Moves to closest one in the direction of step
adds dist.x or dist.y to first_dist .x .y
sets the wall dir to east/west for vertical and north/south for horizontal
checks if its a wall (stops if it is or continues otherwise)
*/
static void	dda_loop(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->cross_dist.x < ray->cross_dist.y)
		{
			ray->map_x += ray->step_x;
			ray->wall_dist = ray->cross_dist.x;
			ray->wall_dir = get_wall_dir(ray);
			ray->cross_dist.x += ray->dist.x;
		}
		else
		{
			ray->map_y += ray->step_y;
			ray->wall_dist = ray->cross_dist.y;
			ray->wall_dir = get_wall_dir(ray);
			ray->cross_dist.y += ray->dist.y;
		}
		if (game->map.map[ray->map_y][ray->map_x] == '1')
		{
			get_wall_size(ray);
			break ;
		}
	}
}

/*
Calculates cross_dir =the distance the ray needs to travel to cross a square in x and y.
Sets the map tile where the player is(the pos but as an int so we just have the tile, not the pos in it);
Calculates distance from the tile to the next considering the direction of the ray and the position in the tile.
sets stepx and y so we know whether it has to move in one or another direction in the axis 
(if raydir is positive it will be +1 and if negative -1)
*/
static void	init_dda(t_game *game, t_ray *ray)
{
	ray->dist.x = fabs(1.0 / ray->raydir.x);
	ray->dist.y = fabs(1.0 / ray->raydir.y);
	ray->map_x = (int)game->player.pos.x;
	ray->map_y = (int)game->player.pos.y;
	if (ray->raydir.x < 0)
	{
		ray->step_x = -1;
		ray->cross_dist.x = (game->player.pos.x - ray->map_x) * ray->dist.x;
	}
	else
	{
		ray->cross_dist.x = (ray->map_x + 1 - game->player.pos.x) * ray->dist.x;
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
		ray->cross_dist.y = (ray->map_y + 1 - game->player.pos.y) * ray->dist.y;
	}
	dda_loop(game, ray);
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
		game->ray.raydir.x = 
			game->player.dir.x + game->player.plane.x * game->ray.cam;
		game->ray.raydir.y = 
			game->player.dir.y + game->player.plane.y * game->ray.cam;
		init_dda(game, &game->ray);
		draw_column(game, x);
		x++;
	}
}
