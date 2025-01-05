#ifndef SO_LONG_H
#define SO_LONG_H

// Tile size (square)
# define SIZE	64

// Frame rate
# define FRAME_RATE	60

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

typedef struct s_enemy
{
	int		x;
	int		y;
	int		direction_x;
	int		direction_y;
	int		is_active;
}	t_enemy;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		total_collectibles;
	int		collected_count;
	int		total_enemies;
	int		player_x;
	int		player_y;
	t_enemy	*enemies;
	int		movement_count;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*img_enemy;
	int		frame;
	int		max_frames;
	int		enemy_animation;
}	t_game;

# include "extra_libs/mlx/mlx.h"
# include "extra_libs/mlx/mlx_int.h"
# include "extra_libs/libft/libft.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

/* map.c */
void	read_map(const char *file, t_map *map);
void	validate_map(t_map *map);

/* game_init.c */
void	init_game(t_game *game);

/* images.c */
void	load_images(t_game *game);

/* render.c */
void	render_map(t_game *game);

/* events.c */
int		handle_keypress(int keycode, t_game *game);
int		close_window(t_game *game);
void	hook_events(t_game *game);

/* free.c */
void	free_resources(t_game *g);

#endif
