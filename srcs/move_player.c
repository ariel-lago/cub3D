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

static void    go_straight(t_player *player, t_map *map)
{
    double  new_x;
    double  new_y;

    new_x = player->pos_x + player->dir_x * player->move_speed;
    new_y = player->pos_y + player->dir_y * player->move_speed;

    if (new_x < 0 || new_x >= map->map_width ||
        new_y < 0 || new_y >= map->map_height)
        return ;
    if (map->map[(int)new_y][(int)new_x] != '1')
    {
        player->pos_x = new_x;
        player->pos_y = new_y;
    }
}

static void    go_back(t_player *player, t_map *map)
{
    double  new_x;
    double  new_y;

    new_x = player->pos_x - player->dir_x * player->move_speed;
    new_y = player->pos_y - player->dir_y * player->move_speed;

    if (new_x < 0 || new_x >= map->map_width ||
        new_y < 0 || new_y >= map->map_height)
        return ;
    if (map->map[(int)new_y][(int)new_x] != '1')
    {
        player->pos_x = new_x;
        player->pos_y = new_y;
    }
}

static void    go_left(t_player *player, t_map *map)
{
    double  new_x;
    double  new_y;

    new_x = player->pos_x + player->dir_y * player->move_speed;
    new_y = player->pos_y - player->dir_x * player->move_speed;

    if (new_x < 0 || new_x >= map->map_width ||
        new_y < 0 || new_y >= map->map_height)
        return ;
    if (map->map[(int)new_y][(int)new_x] != '1')
    {
        player->pos_x = new_x;
        player->pos_y = new_y;
    }
}

static void    go_right(t_player *player, t_map *map)
{
    double  new_x;
    double  new_y;

    new_x = player->pos_x - player->dir_y * player->move_speed;
    new_y = player->pos_y + player->dir_x * player->move_speed;

    if (new_x < 0 || new_x >= map->map_width ||
        new_y < 0 || new_y >= map->map_height)
        return ;
    if (map->map[(int)new_y][(int)new_x] != '1')
    {
        player->pos_x = new_x;
        player->pos_y = new_y;
    }
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
            go_straight(&game->player, &game->map);
        if (game->keys.pressed[KEY_S])
            go_back(&game->player, &game->map);
        if (game->keys.pressed[KEY_A])
            go_left(&game->player, &game->map);
        if (game->keys.pressed[KEY_D])
            go_right(&game->player, &game->map);
        if (game->keys.left)
            rotate_player(&game->player, -game->player.rot_speed);
        if (game->keys.right)
            rotate_player(&game->player, game->player.rot_speed);
        
        return (SUCCESS);
}
