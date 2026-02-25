/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:40:13 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/25 18:51:16 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_file(char	*map_name)
{
	int	len;

	if (!map_name)
		return (error("Missing map name", 0), FALSE);
	len = ft_strlen(map_name);
	if (len < 4 || ft_strncmp(map_name + len - 4, ".cub", 4) != 0)
		return (error("Map needs .cub extension", 0), FALSE);
	return (TRUE);
}
