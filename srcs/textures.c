/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:56:17 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/04 17:57:02 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
