/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:43:23 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/16 18:59:19 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
Writes "Error\n" to stderr
If p flag is activated it sends the message through perror
Otherwise it simply sends the message to strderr
*/
void	error(char *message, int p)
{
	write(2, "Error\n", 6);
	if (p)
		perror(message);
	else
		ft_putendl_fd(message, 2);
}

/* frees any array of fixed size */
void	free_array(void **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/* makes the gnl reach EOF so that 
	no memory is left in the static linked list. 
	(Valgrind -> still reachable)
*/
void	flush_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	clean_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->wall[i].img)
			mlx_destroy_image(game->window.mlx, game->wall[i].img);
		i++;
	}
	if (game->canvas.img)
		mlx_destroy_image(game->window.mlx, game->canvas.img);
}

void	clean_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < 4)
	{
		if (map->walls[i])
			free(map->walls[i]);
		i++;
	}
	if (map->map)
	{
		free_array((void **)map->map);
		map->map = NULL;
	}
	if (map->map_copy)
	{
		free_array((void **)map->map_copy);
		map->map_copy = NULL;
	}
}
