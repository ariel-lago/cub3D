/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:24:08 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/23 17:42:25 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define

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

int	init_window(t_win *window);
int	close_window(t_win *window);

#endif
