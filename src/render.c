#include "../includes/so_long.h"

static void	render_tile(t_game *g, int x, int y)
{
	char c;

	c = g->map.grid[y][x];
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall, x * SIZE, y * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_collectible,
			x * SIZE, y * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit,
			x * SIZE, y * SIZE);
	else if (c == 'X')
		mlx_put_image_to_window(g->mlx, g->win, g->img_enemy,
			x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img_floor,
			x * SIZE, y * SIZE);
}

void	render_map(t_game *g)
{
	int x;
	int y;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			render_tile(g, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img_player,
		g->map.player_x * SIZE, g->map.player_y * SIZE);
}
