/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:22:57 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/24 17:29:48 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game	*game)
{
	move_player(game);
	render(game);

	return (SUCCESS);
}

void	init_game(t_game *game)
{
	int	i;
	
	if (init_window(&game->window) == FAILURE)
		error("Couldn't initialize Window", 0);
	init_player(game);
	i = 0;
	while (i < 4)
	{
		if (load_texture(game, &game->wall[i], game->map.walls[i]) == FAILURE)
			error("Couldn't load Wall texture", 0);
		debug_textures(game, i);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (error ("Try adding one map", 0), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (parse(&game.map, argv[1]) == FAILURE)
		return (error("Map parsing failed", 0), 1);
	init_game(&game);
	mlx_hook(game.window.win, EVENT_KEY_PRESS, 1L<<0, key_hook, &game);
	mlx_hook(game.window.win, EVENT_KEY_RELEASE, 1L<<1, key_release, &game);
	mlx_hook(game.window.win, EVENT_CLOSE, 1L<<17, close_window, &game);
	mlx_loop_hook(game.window.mlx, game_loop, &game);
	mlx_loop(game.window.mlx);
	return (0);
}
