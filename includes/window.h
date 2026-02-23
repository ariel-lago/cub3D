/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:24:08 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/23 19:23:04 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include "cub3d.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef	struct	s_win
{
	void	*mlx;
	void	*win;
	int	width;
	int	height;
	char	*title;
}	t_win;

void	init_window(t_win *window);
int	close_window(t_win *window);

#endif
