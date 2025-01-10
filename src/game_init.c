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
	game->tex_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &w, &h);
	game->tex_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->tex_player || !game->tex_collect || !game->tex_exit)
		error_exit("Failed to load one of the textures.");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Failed to init MLX.");
	game->win = mlx_new_window(game->mlx,
			game->map.width * 64, game->map.height * 64, "so_long");
	if (!game->win)
		error_exit("Failed to create a window.");
	load_textures(game);
	game->moves = 0;
}
