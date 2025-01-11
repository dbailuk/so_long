/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:33:48 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/11 18:06:57 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->tex_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	if (!game->tex_wall)
		error_exit("Failed to load wall texture.");
	game->tex_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	if (!game->tex_floor)
		error_exit("Failed to load floor texture.");
	game->tex_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &w, &h);
	if (!game->tex_player)
		error_exit("Failed to load textures/player.xpm");
	game->tex_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &w, &h);
	if (!game->tex_collect)
		error_exit("Failed to load textures/collect.xpm");
	game->tex_exit_closed = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_closed.xpm", &w, &h);
	game->tex_exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_open.xpm", &w, &h);
	if (!game->tex_exit_closed || !game->tex_exit_open)
		error_exit("Failed to load textures/exit_open or closed .xpm");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Failed to init MLX.");
	game->win = mlx_new_window(game->mlx,
			game->map.width * IMG_W, game->map.height * IMG_H, "so_long");
	if (!game->win)
		error_exit("Failed to create a window.");
	load_textures(game);
	game->moves = 0;
}
