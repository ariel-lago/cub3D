/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:43:23 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/12 15:03:35 by rbestman         ###   ########.fr       */
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
void free_array(void **arr, int size)
{
    int i;

    if (!arr)
        return;
    
    i = 0;
    while (i < size)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void    clean_textures(t_game *game)
{
    int i;

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

	if(!map)
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
        free_array((void **)map->map, map->map_height);
        map->map = NULL;
    }
    if (map->map_copy)
    {
        free_array((void **)map->map_copy, map->map_height);
        map->map_copy = NULL;
    }
}
