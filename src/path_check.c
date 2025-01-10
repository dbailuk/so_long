/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:33:26 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/10 14:33:26 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	explore_map(t_game *g, t_path *p, int y, int x)
{
	static int	d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int			i;

	if (y < 0 || x < 0 || y >= g->map.height || x >= g->map.width)
		return ;
	if (p->visited[y][x] || g->map.grid[y][x] == '1')
		return ;
	p->visited[y][x] = 1;
	if (g->map.grid[y][x] == 'C')
		p->found_c++;
	if (g->map.grid[y][x] == 'E')
		p->found_e = 1;
	i = -1;
	while (++i < 4)
		explore_map(g, p, y + d[i][0], x + d[i][1]);
}

int	is_path_valid(t_game *game)
{
	t_path	p;
	int		r;

	p.found_c = 0;
	p.found_e = 0;
	p.visited = malloc(sizeof(int *) * game->map.height);
	if (!p.visited)
		return (0);
	r = -1;
	while (++r < game->map.height)
		p.visited[r] = ft_calloc(game->map.width, sizeof(int));
	explore_map(game, &p, game->py, game->px);
	while (--r >= 0)
		free(p.visited[r]);
	free(p.visited);
	if (p.found_c == game->map.count_c && p.found_e == 1)
		return (1);
	return (0);
}
