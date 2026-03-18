/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:32:23 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/18 14:31:18 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

int		parse(t_map	*map, char *map_name);

//parse_utils.c
int		get_player_start(t_map *map);
int		parse_rgb(char *rgb_str);

//2d render
void	render_2d_map(t_game *game);
void	toggle_minimap(t_game *game);
int		load_map(char *map_name, t_map *map);
int		get_map_size(int fd, int *height, int *width);

#endif
