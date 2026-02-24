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

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (write(2, "Try adding a map\n", 17), 1);
	ft_memset(&game, 0, sizeof(t_game));
	ft_memset(&game.keys.pressed, 0, sizeof(game.keys.pressed));
	if (parse(&game.map, argv[1]) == FAILURE)
		error("Map parsing failed");
	init_window(&game.window);
	draw_window(&game);
	mlx_hook(game.window.win, EVENT_KEY_PRESS, 1L<<0, key_hook, &game);
	//mlx_hook(game.window.win, EVENT_KEY_RELEASE, 1L<<1, key_release, &game);
	mlx_hook(game.window.win, EVENT_CLOSE, 1L<<17, close_window, &game.window);

	mlx_loop(game.window.mlx);

	return (0);
}
