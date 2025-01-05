#include "../includes/so_long.h"

static int	count_file_lines(const char	*file)
{
	int		fd;
	int		lines;
	char	*tmp;

	lines = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (tmp = get_next_line(fd))
	{
		free(tmp);
		lines++;
	}
	close(fd);
	return (lines);
}

void	read_map(const char	*file, t_map	*map)
{
	int	fd;
	int	i;
	int	lines;

	lines = count_file_lines(file);
	if (lines <= 0)
	{
		ft_putstr_fd("Error: invalid or empty map\n", 2);
		exit(1);
	}
	map->grid = malloc(sizeof(char *) * (lines + 1));
	if (!map->grid)
		exit(1);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < lines)
		map->grid[i++] = get_next_lines(fd);
	map->grid[i] = NULL;
	close(fd);
	map->height = lines;
	map->width = ft_strlen(map->grid[0]) - 1;
}

void	validate_map(t_map	*map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		if ((int)ft_strlen(map->grid[y]) - 1 != map->width)
		{
			ft_putstr_fd("Error: map not rectangular\n", 2);
			exit(1);
		}
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == '\n')
				map->grid[y][x] = '\0';
			x++;
		}
		y++;
	}
}
