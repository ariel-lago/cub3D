/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:22:57 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/23 18:44:53 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (write(2, "Try adding a map\n", 17), 1);
	if (parse(&game.map, argv[1]) == FAILURE)
		error("Map parsing failed");
	init_window(&game.window);

	mlx_key_hook(game.window.win, key_hook, &game);
	mlx_hook(game.window.win, EVENT_CLOSE, 0, close_window, &game.window);

	mlx_loop(game.window.mlx);

	return (0);
}
