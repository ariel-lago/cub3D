/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:04:29 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/23 19:26:42 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 0
# define FAILURE 1

typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		player_dir;
	char	*walls[4];
	char	*floor_color;
	char	*ceiling_color;
}	t_map;

#endif
