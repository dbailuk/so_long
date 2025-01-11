/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:33:22 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/11 18:40:51 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_tile(t_game *g, void *tex, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, tex, x * IMG_W, y * IMG_H);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				put_tile(game, game->tex_wall, x, y);
			else
				put_tile(game, game->tex_floor, x, y);
			if (game->map.grid[y][x] == 'C')
				put_tile(game, game->tex_collect, x, y);
			if (game->map.grid[y][x] == 'E')
			{
				if (game->map.count_c > 0)
					put_tile(game, game->tex_exit_closed, x, y);
				else
					put_tile(game, game->tex_exit_open, x, y);
			}
			x++;
		}
		y++;
	}
	put_tile(game, game->tex_player, game->px, game->py);
}
