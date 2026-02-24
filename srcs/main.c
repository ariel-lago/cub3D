/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:22:57 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/24 17:00:21 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (error ("Error\nTry adding one map"), 1);
	if (parse(&game.map, argv[1]) == FAILURE)
		return (error("Error\nMap parsing failed"), 1);
	init_window(&game.window);
	render_2d_map(&game);
	mlx_key_hook(game.window.win, key_hook, &game);
	mlx_hook(game.window.win, EVENT_CLOSE, 0, close_window, &game.window);
	mlx_loop(game.window.mlx);
	return (0);
}
