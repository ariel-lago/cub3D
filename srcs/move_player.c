/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:53:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/27 15:53:00 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    go_straight(t_player *player, t_map *map)
{
    t_vector    new;

    new.x = player->pos.x + player->dir.x * player->move_speed;
    new.y = player->pos.y + player->dir.y * player->move_speed;

    if (new.x < 0 || new.x >= map->map_width ||
        new.y < 0 || new.y >= map->map_height)
        return ;
    if (map->map[(int)new.y][(int)new.x] != '1')
    {
        player->pos.x = new.x;
        player->pos.y = new.y;
    }
}

static void    go_back(t_player *player, t_map *map)
{
    t_vector    new;

    new.x = player->pos.x - player->dir.x * player->move_speed;
    new.y = player->pos.y - player->dir.y * player->move_speed;

    if (new.x < 0 || new.x >= map->map_width ||
        new.y < 0 || new.y >= map->map_height)
        return ;
    if (map->map[(int)new.y][(int)new.x] != '1')
    {
        player->pos.x = new.x;
        player->pos.y = new.y;
    }
}

static void    go_left(t_player *player, t_map *map)
{
    t_vector    new;

    new.x = player->pos.x + player->dir.x * player->move_speed;
    new.y = player->pos.y - player->dir.y * player->move_speed;

    if (new.x < 0 || new.x >= map->map_width ||
        new.y < 0 || new.y >= map->map_height)
        return ;
    if (map->map[(int)new.y][(int)new.x] != '1')
    {
        player->pos.x = new.x;
        player->pos.y = new.y;
    }
}

static void    go_right(t_player *player, t_map *map)
{
    t_vector    new;

    new.x = player->pos.x - player->dir.x * player->move_speed;
    new.y = player->pos.y + player->dir.y * player->move_speed;

    if (new.x < 0 || new.x >= map->map_width ||
        new.y < 0 || new.y >= map->map_height)
        return ;
    if (map->map[(int)new.y][(int)new.x] != '1')
    {
        player->pos.x = new.x;
        player->pos.y = new.y;
    }
}

/* checks if any relevant keys were pressed
    and moves player/view accordingly */
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

        if (game->keys.down && game->player.fov > 30.00)
            set_player_plane(game, game->player.fov - 1.00);
        if (game->keys.up && game->player.fov < 120.00)
            set_player_plane(game, game->player.fov + 1.00);
        
        return (SUCCESS);
}
