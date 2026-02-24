/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:08:33 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/24 17:31:34 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

typedef struct s_key
{
	bool	pressed[256];	
}	t_key;

typedef struct  s_img
{
        void    *img;
        char    *addr;
        int     bpp;
        int     line_len;
        int     endian;
}       t_img;

typedef struct s_game
{
	t_win	window;
	t_map	map;
	t_key	keys;
	t_img	canvas;
}	t_game;

int     key_hook(int keycode, t_game *game);
int     key_release(int keycode, t_game *game);
void draw_window(t_game *game);
void put_pixel(t_img *img, int x, int y, int color);

//int	game_loop(t_game *game);

#endif
