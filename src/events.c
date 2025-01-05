#include "../includes/so_long.h"

static void	move_player(int keycode, t_game *g)
{
	int nx;
	int ny;

	nx = g->map.player_x;
	ny = g->map.player_y;
	if (keycode == KEY_W || keycode == KEY_UP)
		ny--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ny++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		nx--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		nx++;
	if (g->map.grid[ny][nx] == '1')
		return ;
	g->map.player_x = nx;
	g->map.player_y = ny;
	g->map.movement_count++;
}

int	handle_keypress(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		close_window(g);
	else
		move_player(keycode, g);
	render_map(g);
	return (0);
}

int	close_window(t_game *g)
{
	free_resources(g);
	exit(0);
	return (0);
}

void	hook_events(t_game *g)
{
	mlx_hook(g->win, 2, 1L << 0, handle_keypress, g);
	mlx_hook(g->win, 17, 1L << 17, close_window, g);
}
