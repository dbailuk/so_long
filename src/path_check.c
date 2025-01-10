/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:33:26 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/10 13:40:41 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	explore_map(t_game *g, int y, int x, int **v, int *fc, int *fe)
{
	int			i;
	static int	d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	if (y < 0 || x < 0 || y >= g->map.height || x >= g->map.width)
		return ;
	if (v[y][x] || g->map.grid[y][x] == '1')
		return ;
	v[y][x] = 1;
	if (g->map.grid[y][x] == 'C')
		(*fc)++;
	if (g->map.grid[y][x] == 'E')
		*fe = 1;
	i = -1;
	while (++i < 4)
		explore_map(g, y + d[i][0], x + d[i][1], v, fc, fe);
}

int	is_path_valid(t_game *game)
{
	int	**visited;
	int	r;
	int	found_c;
	int	found_e;

	found_c = 0;
	found_e = 0;
	visited = (int **)malloc(sizeof(int *) * game->map.height);
	if (!visited)
		return (0);
	r = -1;
	while (++r < game->map.height)
		visited[r] = ft_calloc(game->map.width, sizeof(int));
	explore_map(game, game->py, game->px, visited, &found_c, &found_e);
	while (--r >= 0)
		free(visited[r]);
	free(visited);
	if (found_c == game->map.count_c && found_e == 1)
		return (1);
	return (0);
}
