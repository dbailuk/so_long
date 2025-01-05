#include "../includes/so_long.h"

void	free_resources(t_game *g)
{
	int	i;

	if (!g)
		return ;
	i = 0;
	while (g->map.grid && i < g->map.height)
		free(g->map.grid[i++]);
	if (g->map.grid)
		free(g->map.grid);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_collectible)
		mlx_destroy_image(g->mlx, g->img_collectible);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_enemy)
		mlx_destroy_image(g->mlx, g->img_enemy);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}
