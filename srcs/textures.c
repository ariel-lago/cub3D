/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:56:17 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/10 14:29:33 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int get_pixel_color(t_img *img, int x, int y)
{
    char *pixel_data;

    pixel_data = img->addr + (y * img->line_len + x * (img->bpp / 8));
    return (*(unsigned int*)pixel_data);
}


int scale_texture(t_game *game, t_ray *ray, int screen_y)
{
    t_img       *texture;
    int         row;
    int         col;
    double      hit_point;
    double      wall_distance;

    texture = &game->wall[ray->wall_dir];
    row = (screen_y - ray->draw_start) * texture->height/ray->line_height;

    if (ray->wall_dir == EAST || ray->wall_dir == WEST)
    {
        wall_distance = ray->cross_dist.x - ray->dist.x;
        hit_point = game->player.pos.y + ray->raydir.y * wall_distance;
    }
    else
    {
        wall_distance = ray->cross_dist.y - ray->dist.y;
        hit_point = game->player.pos.x + ray->raydir.x * wall_distance;
    }
    col = (fmod(hit_point, 1.0)) * texture->width;
    return (get_pixel_color(texture, col, row));
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
int load_texture(t_game *game, t_img *texture, char *filepath)
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
