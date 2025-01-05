#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed\n", 2);
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx,
		game->map.width * SIZE,
		game->map.height * SIZE,
		"so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error: mlx_new_window failed\n", 2);
		exit(EXIT_FAILURE);
	}
}
