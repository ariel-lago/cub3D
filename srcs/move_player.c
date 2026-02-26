/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:53:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/25 16:53:44 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    go_straight(t_player *player)
{
        player->pos_x += player->dir_x * player->move_speed;
        player->pos_y += player->dir_y * player->move_speed;
}

static void    go_back(t_player *player)
{
        player->pos_x -= player->dir_x * player->move_speed;
        player->pos_y -= player->dir_y * player->move_speed;
}

static void    go_left(t_player *player)
{
        player->pos_x += player->dir_x * player->move_speed;
        player->pos_y -= player->dir_y * player->move_speed;
}

static void    go_right(t_player *player)
{
        player->pos_x -= player->dir_x * player->move_speed;
        player->pos_y += player->dir_y * player->move_speed;
}

static void     rotate_player(t_player *player, double angle)
{
    double  old_dir_x;
    double  old_plane_x;

    old_dir_x = player->dir_x;
    old_plane_x = player->plane_x;
    
    player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
    player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);

    player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
    player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);

}

int     move_player(t_game *game)
{
        if (game->keys.pressed[KEY_W])
            go_straight(&game->player);
        if (game->keys.pressed[KEY_S])
            go_back(&game->player);
        if (game->keys.pressed[KEY_A])
            go_left(&game->player);
        if (game->keys.pressed[KEY_D])
            go_right(&game->player);
        if (game->keys.left)
            rotate_player(&game->player, -game->player.rot_speed);
        if (game->keys.right)
            rotate_player(&game->player, game->player.rot_speed);
        
        return (SUCCESS);
}
