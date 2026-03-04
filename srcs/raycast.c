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
for every column of win width we cast a ray till the next wall
*/
void	cast_rays(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		set_ray_dir(game, &game->ray, x);
		init_dda(game, &game->ray);
		x++;
	}
}
/*
 We set each column to a position in the camera plane (-1.0 to +1.0)
 cam = 0 means it looks straight where the player looks
 cam = 1 means ray leans all the way to the right edge
 cam = -1 means ray leans to the left fully
* */
void	set_ray_dir(t_game *game, t_ray *ray, int x)
{
	ray->cam = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydir.x = game->player.dir.x + game->player.plane.x * ray->cam;
	ray->raydir.y = game->player.dir.y + game->player.plane.y * ray->cam;
}

/*
Calculates the distance the ray needs to travel to cross a square in x and y.
Sets the map tile where the player is;
Calculates distance from first square to the next crossing (since player is in center of square)
sets stepx and y so we know whether it has to move in one or another direction in the axis (if raydir is positive it will be +1 andif negative -1)
*/
void	init_dda(t_game *game, t_ray *ray)
{
	ray->dist.x = ;
	ray->dist.y = ;
	ray->map_x = (int)game->player.pos.x;
	ray->map_y = (int)game->player.pos.y;
	if (ray->raydir.x < 0)
	{
		ray->step_x = -1;
		ray->first_dist.x = ;
	}
	else
	{
		ray->first_dist.x = ;
		ray->step_x = 1;
	}
	if (ray->raydir.y < 0)
	{
		ray->step_y = -1;
		ray->first_dist.y = ;
	}
	else
	{
		ray->step_y = 1;
		ray->first_dist.y = ;
	}
}
