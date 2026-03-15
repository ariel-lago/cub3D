/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:49:11 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/15 18:30:05 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "cub3d.h"

int	is_valid_file(char	*file_name, char *type, char *extension);
int	is_valid_map(t_map	*map); 
int	valid_identifiers(t_map *map, int identifiers);

#endif
