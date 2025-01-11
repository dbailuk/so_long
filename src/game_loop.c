/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:33:44 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/11 17:14:48 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.height)
		free(game->map.grid[i]);
	free(game->map.grid);
	if (game->tex_wall)
		mlx_destroy_image(game->mlx, game->tex_wall);
	if (game->tex_floor)
		mlx_destroy_image(game->mlx, game->tex_floor);
	if (game->tex_player)
		mlx_destroy_image(game->mlx, game->tex_player);
	if (game->tex_collect)
		mlx_destroy_image(game->mlx, game->tex_collect);
	if (game->tex_exit_closed)
		mlx_destroy_image(game->mlx, game->tex_exit_closed);
	if (game->tex_exit_open)
		mlx_destroy_image(game->mlx, game->tex_exit_open);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	move_player(t_game *g, int nx, int ny)
{
	if (g->map.grid[ny][nx] == '1')
		return ;
	if (g->map.grid[ny][nx] == 'C')
	{
		g->map.count_c--;
		g->map.grid[ny][nx] = '0';
	}
	g->px = nx;
	g->py = ny;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	if (g->map.grid[ny][nx] == 'E' && g->map.count_c == 0)
		close_game(g);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, game->px, game->py - 1);
	else if (keycode == KEY_S)
		move_player(game, game->px, game->py + 1);
	else if (keycode == KEY_A)
		move_player(game, game->px - 1, game->py);
	else if (keycode == KEY_D)
		move_player(game, game->px + 1, game->py);
	render_map(game);
	return (0);
}
