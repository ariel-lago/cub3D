/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:04:29 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/09 12:08:54 by rbestman         ###   ########.fr       */
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
# define KEY_UP 65362
# define KEY_DOWN 65364

# define EVENT_CLOSE 17
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

#define	VERTICAL 0
#define HORIZONTAL 1

# define PI 3.14159265358979323846
# define DEG_TO_RAD(deg) ((deg) * PI / 180.0)

/*
# define EVENT_MOUSE_PRESS 4
# define EVENT_MOUSE_RELEASE 5
# define EVENT_MOUSE_MOVE 6 */

# include "cub3d.h"

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_direction;

typedef struct s_key
{
	bool	pressed[256];
	bool	left;
	bool	right;
	bool	up;
	bool	down;
}	t_key;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*title;
}	t_win;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		move_speed;
	double		rot_speed;
	double		fov;
}	t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

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

typedef struct s_ray
{
	double		cam;
	int			map_x;
	int			map_y;
	t_vector	dist;
	t_vector	cross_dist;
	int			step_x;
	int			step_y;
	t_vector	raydir;
	double		raypos;
	int			wall_type;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_game
{
	t_win		window;
	t_map		map;
	t_key		keys;
	t_img		canvas;
	t_img		wall[4];
	t_player	player;
	t_ray		ray;
}	t_game;

#endif
