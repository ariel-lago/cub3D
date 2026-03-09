/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:56:17 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/09 11:11:27 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    return (SUCCESS);
}
