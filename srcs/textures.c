/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:56:17 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/16 18:58:57 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  Gets color of pixel at (x, y)
    Offset = (y * bytes per row) + (x * bytes per pixel)
    Added to image buffer start to locate pixel,
    returns the 4 bytes at the pixel's location
    casted as int (works for bpp = 32)
*/
static int	get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel_data;

	pixel_data = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)pixel_data);
}

static double	get_scaled_col(t_game *game, t_ray *ray, t_img *texture)
{
	double	hit_point;

	if (ray->wall_dir == EAST || ray->wall_dir == WEST)
		hit_point = game->player.pos.y + (ray->raydir.y * ray->wall_dist);
	else
		hit_point = game->player.pos.x + (ray->raydir.x * ray->wall_dist);
	return ((fmod(hit_point, 1.0)) * texture->width);
}

/*  Draws a column of wall size for current ray
	- Selects wall texture based on wall_dir
	- Calculates texture scaling factor (step)
	- Gets fixed texture column (scaled.x) for entire column projection
	- Steps through texture rows (scaled.y) as we draw screen rows
*/
void	draw_column(t_game *game, int x)
{
	int			y;
	double		step;
	t_vector	scaled;
	t_img		*texture;

	texture = &game->wall[game->ray.wall_dir];
	step = (double)texture->height / game->ray.line_height;
	scaled.x = get_scaled_col(game, &game->ray, texture);
	y = game->ray.draw_start;
	scaled.y = 0.0;
	while (y <= game->ray.draw_end)
	{
		put_pixel(&game->canvas, x, y, 
			get_pixel_color(texture, (int)scaled.x, (int)scaled.y));
		scaled.y += step;
		y++;
	}
}

/*  loads a xpm texture file into memory using
    mlx_xpm_file_to_image():
        - Parses xpm file, 
        - Allocates GPU-compatible (XShm) memory,
        - Decodes xpm format into raw pixel data
    mlx_get_data_addr():
        Provides pixel access for texture mapping
        by extracting & copying address values 
        from t_img struct (filled by xpm_file_to_image())
    Returns SUCCESS if texture loads, FAILURE otherwise.
*/
int	load_texture(t_game *game, t_img *texture, char *filepath)
{
	texture->img = mlx_xpm_file_to_image(game->window.mlx, filepath,
			&texture->width, &texture->height);
	if (!texture->img)
		return (FAILURE);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (FAILURE);
	return (SUCCESS);
}
