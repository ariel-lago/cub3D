/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:46:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/05 13:48:57 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* prints end pos, dir (converted into actual directions) and FOV.
    uses printf -> delete or change ft_printf before submission.
*/
void	print_end_stats(t_game *game)
{
    printf("\n===GAME OVER===\n");
    printf("Final position: (%d, %d)\n", (int)game->player.pos.x, (int)game->player.pos.y);
    printf("Final direction: (%.2f, %.2f) -> ", game->player.dir.x, game->player.dir.y);
    if (game->player.dir.x > 0 && game->player.dir.y < 0)  // Northeast quadrant
        printf("NE");
    else if (game->player.dir.x > 0 && game->player.dir.y > 0)  // Southeast quadrant
        printf("SE");
    else if (game->player.dir.x < 0 && game->player.dir.y < 0)  // Northwest quadrant
        printf("NW");
    else if (game->player.dir.x < 0 && game->player.dir.y > 0)  // Southwest quadrant
        printf("SW");
    else if (game->player.dir.y < -0.90)  // North sector
        printf("N");
    else if (game->player.dir.y > 0.90)  // South sector
        printf("S");
    else if (game->player.dir.x > 0.92)  // East sector
        printf("E");
    else if (game->player.dir.x < -0.9)  // West sector
        printf("W");
    printf("\n");
    printf("Final FOV: %.1f°, rad %.2f\n", game->player.fov, game->player.fov * PI / 180.0);
}

//DEBUG -> prints start stats 
void	print_start_stats(t_game *game)
{
    ft_printf("\n=== START GAME ===\n");
    ft_printf("Initial position: (%d, %d)\n", 
        (int)game->player.pos.x, (int)game->player.pos.y);
    ft_printf("Initial direction: (%d, %d) -> %c\n",
        (int)game->player.dir.x, (int)game->player.dir.y, game->map.player_dir);
    printf("FOV: %.1f°, rad %.2f\n", game->player.fov, game->player.fov * PI / 180.0);
}
