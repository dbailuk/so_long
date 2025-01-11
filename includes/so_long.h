/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:33:36 by dbailuk           #+#    #+#             */
/*   Updated: 2025/01/11 18:34:26 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_W 32
# define IMG_H 32

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# include "../extra_libs/mlx/mlx.h"
# include "../extra_libs/mlx/mlx_int.h"
# include "../extra_libs/libft_gnl/includes/libft.h"
# include "../extra_libs/ft_printf/ft_printf.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_path
{
	int	**visited;
	int	found_c;
	int	found_e;
}	t_path;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		count_c;
	int		count_e;
	int		count_p;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*tex_wall;
	void	*tex_floor;
	void	*tex_player;
	void	*tex_collect;
	void	*tex_exit_closed;
	void	*tex_exit_open;
	int		moves;
	int		px;
	int		py;
	t_map	map;
}	t_game;

// main.c
int		main(int argc, char **argv);
void	error_exit(char *msg);
// map_parse.c
void	parse_map(char *file, t_game *game);
// map_check.c
void	check_map(t_game *game);
// path_check.c
int		is_path_valid(t_game *game);
// game_init.c
void	init_game(t_game *game);
// game_loop.c
int		handle_keypress(int keycode, t_game *game);
int		close_game(t_game *game);
// render.c
void	render_map(t_game *game);
int		handle_expose(t_game *game);

#endif
