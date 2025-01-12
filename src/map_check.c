/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:33:36 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/12 13:22:38 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_items(char c, t_map *map)
{
	if (c == 'C')
		map->count_c++;
	else if (c == 'E')
		map->count_e++;
	else if (c == 'P')
		map->count_p++;
}

static void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->width)
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			error_exit("Map not surrounded by walls (top/bottom).");
	j = -1;
	while (++j < map->height)
		if (map->grid[j][0] != '1' || map->grid[j][map->width - 1] != '1')
			error_exit("Map not surrounded by walls (left/right).");
}

static void	check_valid_chars(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		if ((int)ft_strlen(map->grid[y]) != map->width)
			error_exit("Map rows are not rectangular.");
		while (map->grid[y][++x])
		{
			if (!ft_strchr("01CEP", map->grid[y][x]))
				error_exit("Invalid character in map.");
		}
	}
}

void	check_map(t_game *game)
{
	t_map	*m;

	m = &game->map;
	if (!m->grid || m->height < 3 || m->width < 3)
		error_exit("Map is too small or not read properly.");
	check_walls(m);
	check_valid_chars(m);
	if (m->count_p != 1)
		error_exit("Map must have exactly 1 player (P).");
	if (m->count_e != 1)
		error_exit("Map must have exactly 1 exit (E).");
	if (m->count_c < 1)
		error_exit("Map must have at least 1 collectible (C).");
}
