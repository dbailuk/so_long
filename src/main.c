#include "../includes/so_long.h"

static void	print_usage(void)
{
	ft_putstr_fd("Correct arguments: ./so_long <map.ber>\n", 2);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if(argc != 2)
	{
		print_usage();
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	read_map(argv[1], &game.map);
	validate_map(&game.map);
	init_game(&game);
	load_icons(&game);
	render_map(&game);
	hook_events(&game);
	mlx_loop(game.mlx);
	free_resorces(&game);
	return (0);
}
