/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:07:08 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/24 14:07:21 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_size(const char *filename, int *height, int *width)
{
	char	*line;
	int		fd;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line) - 1;
		if (*height == 0)
			*width = len;
		else if (len != *width)
			return (free(line), close(fd), \
			ft_printf("Map needs to be rectangular\n"), 0);
		(*height)++;
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	if (*width < 3 || *height < 3)
		return (ft_printf("Map is too small\n"), 0);
	return (1);
}

int	load_map(const char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	game->map = malloc(sizeof(char *) * game->map_height);
	if (!game->map)
	{
		close(fd);
		return (0);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}
