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

static void	add_line_to_grid(t_map *map, char *line)
{
	char	**tmp;
	int		i;

	tmp = map->grid;
	map->grid = ft_calloc(map->height + 2, sizeof(char *));
	if (!map->grid)
		error_exit("Memory allocation failed while reading map.");
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = tmp[i];
		i++;
	}
	map->grid[i] = line;
	free(tmp);
}

static void	read_map_lines(int fd, t_map *map)
{
	char	*line;
	int		current_width;

	map->height = 0;
	map->grid = NULL;
	line = get_next_line(fd);
	while (line)
	{
		strip_newline(line);
		current_width = ft_strlen(line);
		if (map->height == 0)
			map->width = current_width;
		else if (current_width != map->width)
			error_exit("Map is not rectangular.");
		add_line_to_grid(map, line);
		map->height++;
		line = get_next_line(fd);
	}
}

static void	populate_map_data(t_game *game)
{
	int	row;
	int	col;

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

void	parse_map(char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open map file.");
	read_map_lines(fd, &game->map);
	close(fd);
	if (game->map.height == 0)
		error_exit("Map is empty.");
	game->map.width = (int)ft_strlen(game->map.grid[0]);
	populate_map_data(game);
}
