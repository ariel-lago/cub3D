/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:32:23 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/23 19:24:56 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

int	parse(t_map	*map, char *map_name);

//2d render
void    render_2d_map(t_game *game);
int     load_map(char *map_name, t_map *map);
int     get_map_size(char *map_name, int *height, int *width);

#endif
