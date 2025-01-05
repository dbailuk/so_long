#include "../includes/so_long.h"

static void	check_img(void *img, char *err)
{
	if (!img)
	{
		ft_putstr_fd(err, 2);
		exit(1);
	}
}

void	load_images(t_game *g)
{
	int	w;
	int	h;

	g->img_wall = mlx_xpm_file_to_image(g->mlx, "assets/wall.xpm", &w, &h);
	check_img(g->img_wall, "Error: wall.xpm\n");
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "assets/floor.xpm", &w, &h);
	check_img(g->img_floor, "Error: floor.xpm\n");
	g->img_player = mlx_xpm_file_to_image(g->mlx, "assets/player.xpm", &w, &h);
	check_img(g->img_player, "Error: player.xpm\n");
	g->img_collectible = mlx_xpm_file_to_image(g->mlx,
			"assets/collectible.xpm", &w, &h);
	check_img(g->img_collectible, "Error: collectible.xpm\n");
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "assets/exit.xpm", &w, &h);
	check_img(g->img_exit, "Error: exit.xpm\n");
	g->img_enemy = mlx_xpm_file_to_image(g->mlx, "assets/enemy.xpm", &w, &h);
	check_img(g->img_enemy, "Error: enemy.xpm\n");
}
