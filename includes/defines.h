/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:04:29 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/24 14:41:20 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 0
# define FAILURE 1

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define EVENT_CLOSE 17
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define KEY_ESC 65307

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

/*
# define EVENT_MOUSE_PRESS 4
# define EVENT_MOUSE_RELEASE 5
# define EVENT_MOUSE_MOVE 6 */

# include "cub3d.h"

typedef struct s_key
{
	bool	pressed[256];
	bool	left;
	bool	right;
}	t_key;

typedef struct  s_img
{
        void    *img;
        char    *addr;
        int     bpp;
        int     line_len;
        int     endian;
}       t_img;

typedef	struct	s_win
{
	void	*mlx;
	void	*win;
	int	width;
	int	height;
	char	*title;
}	t_win;

typedef	struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
    double  plane_x;
    double  plane_y;
	double	move_speed;
	double  rot_speed;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		player_dir;
	char	*walls[4];
	int		floor_color;
	int		ceiling_color;
}	t_map;

typedef struct s_game
{
	t_win	        window;
	t_map	        map;
	t_key	        keys;
	t_img           canvas;
        t_player        player;
}	t_game;



#endif
