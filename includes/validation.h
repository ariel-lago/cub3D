/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:49:11 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/16 19:51:44 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "cub3d.h"

int	is_valid_file(char	*file_name, char *type, char *extension);
int	is_valid_map(t_map	*map);
int	valid_identifiers(t_map *map, int identifiers);
int	has_one_player(t_map *map);
int	is_surrounded(t_map *map);

#endif
