/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:46:18 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/12 14:08:52 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

void	error(char *message, int p);
void    free_array(void **arr, int size);
void    clean_map(t_map *map);
void    clean_textures(t_game *game);

#endif
