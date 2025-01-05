#include "../includes/so_long.h"

void	init_enemies(t_game *g)
{
	int	x;
	int	y;
	int	idx;

	if (!g->map.total_enemies)
		return ;
	g->map.enemies = malloc(sizeof(t_enemy) * g->map.total_enemies);
	if (!g->map.enemies)
		exit(1);
	idx = 0;
	y = -1;
	while (++y < g->map.height)
	{
		x = -1;
		while (++x < g->map.width)
		{
			if (g->map.grid[y][x] == 'X')
			{
				g->map.enemies[idx].x = x;
				g->map.enemies[idx].y = y;
				g->map.enemies[idx].direction_x = 1;
				g->map.enemies[idx].direction_y = 0;
				g->map.enemies[idx++].is_active = true;
			}
		}
	}
}

void	move_enemies(t_game *g)
{
	int		i;
	int		nx;
	int		ny;
	t_enemy	*e;

	i = 0;
	while (i < g->map.total_enemies)
	{
		e = &g->map.enemies[i++];
		if (!e->is_active)
			continue ;
		nx = e->x + e->direction_x;
		ny = e->y + e->direction_y;
		if (g->map.grid[ny][nx] == '1' || g->map.grid[ny][nx] == 'E')
			e->direction_x = -e->direction_x;
		else
		{
			e->x += e->direction_x;
			e->y += e->direction_y;
		}
	}
}

int	check_enemy_collision(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->map.total_enemies)
	{
		if (g->map.enemies[i].x == g->map.player_x
			&& g->map.enemies[i].y == g->map.player_y)
			return (true);
		i++;
	}
	return (0);
}
