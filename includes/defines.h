/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:04:29 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/23 17:08:04 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "cub3D.h"

typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		player_dir;
	void	*walls[4];
	void	floor;
	void	ceiling;
}	t_map;

#endif
