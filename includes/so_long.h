#ifndef SO_LONG_H
#define SO_LONG_H

# define SIZE	32

// Keys for linux
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
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
    char    **grid;       // 2D array of map chars
    int     width;        // map width
    int     height;       // map height
    int     count_c;      // collectible count
    int     count_e;      // exit count
    int     count_p;      // player count
}   t_map;

typedef struct s_game
{
	void	*mlx;         // MLX instance
	void	*win;         // window
	void    *tex_wall;    // example texture pointers
    void    *tex_floor;
    void    *tex_player;
    void    *tex_collect;
    void    *tex_exit;
    int     moves;        // move counter
    int     px;           // player x (in grid coords)
    int     py;           // player y (in grid coords)
    t_map   map;          // embedded map struct
}   t_game;

// main.c
int	main(int argc, char **argv);
void error_exit(char *msg);

// map_parse.c
void	parse_map(char *file, t_game *game);

// map_check.c
void	check_map(t_game *game);

// path_check.c
int	is_path_valid(t_game *game);

// game_init.c
void	init_game(t_game *game);

// game_loop.c
int	handle_keypress(int keycode, t_game *game);
int	close_game(t_game *game);

// render.c
void	render_map(t_game *game);

#endif
