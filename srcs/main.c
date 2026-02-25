/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:22:57 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/25 18:51:58 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (error ("Try adding one map", 0), 1);
	if (is_valid_file(argv[1]) == FALSE)
		return (1);
	if (parse(&game.map, argv[1]) == FAILURE)
		return (error("Map parsing failed", 0), 1);
	init_window(&game.window);
	render(&game);
	mlx_hook(game.window.win, EVENT_KEY_PRESS, 1L<<0, key_hook, &game);
	//mlx_hook(game.window.win, EVENT_KEY_RELEASE, 1L<<1, key_release, &game);
	mlx_hook(game.window.win, EVENT_CLOSE, 1L<<17, close_window, &game.window);
	mlx_loop(game.window.mlx);
	return (0);
}
