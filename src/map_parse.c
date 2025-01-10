/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:33:32 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/10 13:40:58 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	count_items(char c, t_map *map)
{
	if (c == 'C')
		map->count_c++;
	else if (c == 'E')
		map->count_e++;
	else if (c == 'P')
		map->count_p++;
}

static void	strip_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && (line[len - 1] == '\n'
			|| line[len - 1] == '\r'))
		line[len - 1] = '\0';
}

static void	read_map_lines(int fd, t_map *map)
{
	char	*line;
	char	**tmp;
	int		i;

	map->height = 0;
	map->grid = NULL;
	while ((line = get_next_line(fd)))
	{
		strip_newline(line);
		i = 0;
		tmp = map->grid;
		map->grid = ft_calloc(map->height + 2, sizeof(char *));
		while (i < map->height)
		{
			map->grid[i] = tmp[i];
			i++;
		}
		map->grid[i] = line;
		free(tmp);
		map->height++;
	}
}

void	parse_map(char *file, t_game *game)
{
	int	fd;
	int	row;
	int	col;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	read_map_lines(fd, &game->map);
	close(fd);
	if (game->map.height == 0)
		error_exit("Map is empty.");
	game->map.width = (int)ft_strlen(game->map.grid[0]);
	row = -1;
	while (++row < game->map.height)
	{
		col = -1;
		while (++col < game->map.width)
		{
			count_items(game->map.grid[row][col], &game->map);
			if (game->map.grid[row][col] == 'P')
			{
				game->px = col;
				game->py = row;
			}
		}
	}
}
