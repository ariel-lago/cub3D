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

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (error ("Error\nTry adding one map"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (parse(&game.map, argv[1]) == FAILURE)
		return (error("Error\nMap parsing failed"), 1);
	init_player(&game);
	if (init_window(&game.window) == FAILURE)
		return (error("Error initializing Window"), 1);
	
	mlx_hook(game.window.win, EVENT_KEY_PRESS, 1L<<0, key_hook, &game);
	mlx_hook(game.window.win, EVENT_KEY_RELEASE, 1L<<1, key_release, &game);
	mlx_hook(game.window.win, EVENT_CLOSE, 1L<<17, close_window, &game);
	mlx_loop_hook(game.window.mlx, game_loop, &game);
	mlx_loop(game.window.mlx);
	return (0);
}
