/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:24:08 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/24 17:31:30 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include "cub3d.h"

//void put_pixel(t_img *img, int x, int y, int color);
//void draw_window(t_game *game);
int	init_window(t_win *window);
int	close_window(t_game *game);

#endif
