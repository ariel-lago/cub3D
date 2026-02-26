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

int     key_hook(int keycode, t_game *game);
int     key_release(int keycode, t_game *game);
void	render(t_game *game);
void    create_canvas(t_game *game);
void    draw_window(t_game *game);
void    put_pixel(t_img *img, int x, int y, int color);
void    init_player(t_game *game);
int     move_player(t_game *game);
//int	game_loop(t_game *game);

#endif
