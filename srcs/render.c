/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:48:21 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/12 21:31:34 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Fills pixel at (x, y) with color
    Offset = (y * bytes per row) + (x * bytes per pixel)
    Added to image buffer start to locate pixel,
    writes all 4 bytes to fill with color
    (works w bpp = 32)
*/
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel_data;

	pixel_data = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel_data = color;
}

/* Fills window with (top)half ceiling, (bottom)half floor
    Iterates through every pixel row by row, column by column
    Uses WIN_HEIGHT/2 as dividing line between colors.
*/
void	draw_window(t_game *game)
{
	int	x;
	int	y;

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

/*  (Re)Creates main drawing buffer (canvas) calling
	- mlx_destroy_image():
		 frees existing canvas (XShm Memory).
	- mlx_new_image():
		 gives empty image memory buffer 
		 based on window dimensions.
	- mlx_get_data_addr():
		Provides pixel access for texture mapping
        by extracting & copying address values 
        from t_img struct (filled by xpm_new_image()).
*/
int	create_canvas(t_game *game)
{
	if (game->canvas.img)
		mlx_destroy_image(game->window.mlx, game->canvas.img);
	game->canvas.img = mlx_new_image(game->window.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->canvas.img)
		return (FAILURE);
	game->canvas.addr = mlx_get_data_addr(game->canvas.img,
			&game->canvas.bpp,
			&game->canvas.line_len,
			&game->canvas.endian);
	return (SUCCESS);
}

/*	Main rendering function called each frame.
	Uses static variables to track player stats (pos, dir, fov)
	Only when something changed:
	1. recreates empty canvas, draws 3D view, overlays 2D minimap
	2. calls mlx_put_image_to_window():
		Transfers the image buffer to the visible window,
		telling the X Server to put it at top-left corner (0, 0).
		-> uses XShm to avoid copying/passing memory data.
*/
void	render(t_game *game)
{
	static t_vector	last_pos;
	static t_vector	last_dir;
	static double	last_fov;

	if (last_pos.x != game->player.pos.x || last_pos.y != game->player.pos.y || \
		last_dir.x != game->player.dir.x || last_dir.y != game->player.dir.y || \
		last_fov != game->player.fov)
	{
		if (create_canvas(game) == FAILURE)
			error("MLX failed to create canvas", 0);
		draw_window(game);
		cast_rays(game);
		render_2d_map(game);
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->canvas.img, 0, 0);
		last_pos.x = game->player.pos.x;
		last_pos.y = game->player.pos.y;
		last_dir.x = game->player.dir.x;
		last_dir.y = game->player.dir.y;
	}
}
