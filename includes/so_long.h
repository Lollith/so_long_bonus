/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:13:04 by agouet            #+#    #+#             */
/*   Updated: 2022/04/05 11:52:24 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

# define MLX_ERROR		1
# define IMG_ERROR		1
# define FAILURE		1
# define SUCCESS		0
# define RIGHT			0
# define LEFT			1
# define CLOSE			1
# define OPEN			0
# define NB_PIXELS		42

# define BACKGROUND		"./assets/terrain1.xpm"
# define WALL			"./assets/wall.xpm"
# define HEROES			"./assets/heroes.xpm"
# define HEROES_LEFT	"./assets/heroesleft.xpm"
# define ITEMS			"./assets/items1.xpm"
# define EXIT			"./assets/gate2.xpm"
# define EXIT_OPEN		"./assets/open_gate2.xpm"
# define END_GAME		"./assets/endgame.xpm"

typedef struct s_data_img
{
	char	*addr;
	void	*background;
	void	*wall;
	void	*heroes[2];
	void	*items;
	void	*e_xit[2];
	void	*end_game;
	int		width;
	int		height;
	int		x;
	int		y;
	int		position;
	int		count;
	int		state;
}			t_img;

typedef struct s_data_map
{
	char		*ber;
	char		*map;
	char		*cut_map;
	int			len_line;
	int			len1;
	int			check_line;
}				t_map;

typedef struct s_data_win
{
	int			win_width;
	int			win_height;
}				t_win;

typedef struct s_data_direction
{
	int			right;
	int			left;
	int			up;
	int			down;
}				t_dir;

typedef struct s_data
{
	void		*pt_mlx;
	void		*pt_win;
	t_img		end_game;
	t_map		map;
	t_win		win;
	t_img		img;
	t_img		heroes;
	t_img		items;
	t_img		e_xit;
	t_dir		direction;
}					t_data;

//------------------------------------------------------------------------------
									/*WINDOW*/
//------------------------------------------------------------------------------

void	def_window_size(t_data *data);
int		create_mlx(t_data *data);
int		create_window(t_data *data);

//------------------------------------------------------------------------------
									/*GAME*/
//------------------------------------------------------------------------------

void	initialisation(t_data *data);
void	count_items_ini(t_data *data);
int		render_map(t_data *data);
int		ft_exit(t_data *data);

//------------------------------------------------------------------------------
									/*HOOK*/
//------------------------------------------------------------------------------

int		esc_hook(int keysym, t_data *data);
int		ft_close(t_data *data);
int		keypress( int keysym, t_data *data);
void	ft_key_loop_hook(t_data *data);

//------------------------------------------------------------------------------
									/*move*/
//------------------------------------------------------------------------------

int		ft_move(t_data *data, int *direction);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_right(t_data *data);
int		move_left(t_data *data);

//------------------------------------------------------------------------------
									/*MAPS*/
//------------------------------------------------------------------------------

void	cut_map(t_data *data);
char	*get_map(t_data *data, int fd);
int		count_line(t_data *data);
int		create_map(t_data *data);

//------------------------------------------------------------------------------
								/*CHECKS_MAP*/
//------------------------------------------------------------------------------

int		check_line(char *line, t_data *data);
int		checks_map(t_data *data);
int		check_wall1(t_data *data);
int		check_walls(t_data *data);
int		check_position(t_data *data);

//------------------------------------------------------------------------------
								/*RENDERS*/
//------------------------------------------------------------------------------

void	exit_anim(t_data *data, int *pt_i);
void	heroes_position(t_data *data, int *pt_i);
void	put_image_map(t_data *data);
void	put_heroes(t_data *data);
void	put_fix_image_ini(t_data *data, int *pt_i);
void	animation(t_data *data);

//------------------------------------------------------------------------------
								/*UTILS*/
//------------------------------------------------------------------------------

int		ft_putchar(int c);
int		ft_putnbr(int n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_free(t_data *data);

//------------------------------------------------------------------------------
								/*IMG*/
//------------------------------------------------------------------------------

void	ft_distroy_img(t_data *data);
int		check_img(t_data *data);
int		files_to_images(t_data *data);

//------------------------------------------------------------------------------
								/*ERRORS*/
//------------------------------------------------------------------------------
int		msg_perror(char *origin);
int		msg_error(char *error);

#endif
