/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:21:39 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 18:06:01 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_HEADER_H
# define FT_GAME_HEADER_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"

# define BACKWARD			1
# define FORWARD			13
# define LEFT				0
# define RIGHT				2
# define ESC				53
# define LEFTROT			123
# define RIGHTROT			124
# define REGHT_CLICK_MOUSE	1
# define LEFT_CLICK_MOUSE	2
# define NORTH				1
# define SOUTH				2
# define WEST				3
# define EAST				4
# define FOV				1.04666666667
# define CL					0x00FFFF00

typedef struct s_win_list
{
	void		*init;
	void		*new_win;
	void		*pictures;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*new_win_3d;
	void		*pictures_3d;
	char		*addr_3d;
	int			bits_per_pixel_3d;
	int			line_length_3d;
	int			endian_3d;
}				t_win_list;

typedef struct s_n_t
{
	char		*path_n_t;
	void		*n_t;
	int			n_t_w;
	int			n_t_h;
	char		*addr_n_t;
	float		kef_n_t_w;
	float		kef_n_t_h;
	int			n_t_b;
	int			n_t_l;
	int			n_t_e;
}				t_n_t;

typedef struct s_s_t
{
	char		*path_s_t;
	void		*s_t;
	int			s_t_w;
	int			s_t_h;
	char		*addr_s_t;
	float		kef_s_t_w;
	float		kef_s_t_h;
	int			s_t_b;
	int			s_t_l;
	int			s_t_endian;
}				t_s_t;

typedef struct s_w_t
{
	char		*path_w_t;
	void		*w_t;
	int			w_t_w;
	int			w_t_h;
	char		*addr_w_t;
	float		kef_w_t_w;
	float		kef_w_t_h;
	int			w_t_b;
	int			w_t_l;
	int			w_t_e;
}				t_w_t;

typedef struct s_e_t
{
	char		*path_e_t;
	void		*e_t;
	int			e_t_w;
	int			e_t_h;
	char		*addr_e_t;
	float		kef_e_t_w;
	float		kef_e_t_heiht;
	int			e_t_b;
	int			e_t_l;
	int			e_t_e;
}				t_e_t;

typedef struct s_sp_t
{
	char		*path_sp_t;
	void		*sp_t;
	int			sp_t_w;
	int			sp_t_h;
	char		*addr_sp_t;
	float		kef_sp_t_w;
	float		kef_sp_t_h;
	int			sp_t_b;
	int			sp_t_l;
	int			sp_t_e;
}				t_sp_t;

typedef struct s_list_item
{
	int					hp;
	int					type_item;
	float				x;
	float				y;
	float				distance_from_the_player;
	int					visable;
	double				sprite_dir;
	double				sprite_size;
	double				a;
	double				h;
	int					key;
	double				h_offset;
	double				v_offset;
	struct s_list_item	*next;
}				t_list_item;

typedef struct s_map_list
{
	char		*filename;
	char		**map;
	int			height;
	int			width;
	char		**p_f;
	t_n_t		*n_t;
	t_s_t		*s_t;
	t_w_t		*w_t;
	t_e_t		*e_t;
	t_sp_t		*sp_t;
	int			floor_color[3];
	int			floor_collor_ox;
	int			ceilling_color[3];
	int			ceilling_color_ox;
	t_list_item	*sprite;
	int			*h_reicasting;
}				t_map_list;

typedef struct s_list_key_moving
{
	int			backward;
	int			forvard;
	int			left;
	int			right;
	int			leftrot;
	int			rightrot;
	int			right_click_mouse;
	int			left_click_mouse;
}				t_list_key_moving;

typedef struct s_list_mouse_manager
{
	float		central_x;
	float		central_y;
	int			right_click_mouse;
	int			left_click_mouse;
}				t_list_mouse_manager;

typedef struct s_list_main_hero_management
{
	t_list_key_moving		*key_press;
	t_list_mouse_manager	*mouse_manager;
	int						hp_main_hero;
	int						def_main_hero;
	int						live_main_hero;
	int						x;
	int						first_x;
	int						first_y;
	int						y;
	float					v_d;
	float					first_v_d;
}				t_list_main_hero_management;

typedef struct s_line_list
{
	double		x;
	double		y;
	double		a;
	int			i;
	int			j;
	int			wall;
	double		h_wall;
}				t_line_list;

typedef struct s_all_game_list
{
	t_line_list					*line;
	t_win_list					*win;
	t_map_list					*map;
	t_list_main_hero_management	*hero;
}				t_all_game_list;

int		create_3d_win(t_win_list *win);
int		map_parser(t_map_list *map, t_win_list *win, char *argv);
int		parser_screen_resolution(t_map_list *map);
int		parser_texure(t_map_list *map, t_win_list *win);
int		parser_norse_texture(t_map_list *map, t_win_list *win);
int		parser_s_t(t_map_list *map, t_win_list *win);
int		parser_w_t(t_map_list *map, t_win_list *win);
int		parser_e_t(t_map_list *map, t_win_list *win);
int		parser_sp_t(t_map_list *map, t_win_list *win);
int		create_celling_collor(t_map_list *map);
int		create_floor_collor(t_map_list *map);
int		create_celling_collor_ox(t_map_list *map);
int		crete_floor_color_xo(t_map_list *map);
int		parser_color(t_map_list *map);
int		parsing_p_f(t_map_list*map);
int		create_map(t_win_list *win, t_map_list *map,
			t_list_main_hero_management *hero);
int		create_wall(t_win_list *win, int i, int j);
int		create_item(t_win_list *win, int i, int j);
int		create_floor_and_sky(t_win_list *win, t_map_list *map);
int		create_hero(t_map_list *map, \
			t_list_main_hero_management *hero, int i, int j);
void	hero_position(t_map_list *map, \
			t_list_main_hero_management *hero, int i, int j);
void	painting_hero(t_win_list *win, t_list_main_hero_management *hero);
int		ray_calculation(t_all_game_list *game);
int		validation_map(t_map_list *map);
void	validation_screen_extension(t_map_list *map);
int		validation_image(t_map_list *map);
int		validatiom_collor(t_map_list *map);
int		validation_p_f(t_map_list *map);
int		check_key_button(int key, t_all_game_list *game);
int		key_realize(int key, t_all_game_list *game);
int		check_mouse_hook(int mousecode, t_all_game_list *game);
int		mouse_realize(int mousecode, t_all_game_list *game);
int		changes_v_d(t_all_game_list *game);
int		moving_main_hero(t_all_game_list *game);
int		destroy_image(t_all_game_list *game);
int		create_pictures(t_all_game_list *game);
int		rendering_pictures(t_all_game_list *game);
int		which_texture_print_ox(double a);
int		which_texture_print_oy(double a);
int		where_did_raycasting_fall(t_all_game_list *game,
			double x, double y, int wall);
int		create_3d_map_line_sprite(t_all_game_list *game, int i);
int		create_3d_map_texture(t_all_game_list *game, double h, double j);
int		create_3d_map_list_ceilling(t_all_game_list *game, double h, double j);
int		create_3d_map_list_floor(t_all_game_list *game, double h, double j);
int		create_3d_map_line(t_all_game_list *game, double h, double j);
int		print_n_t_line(t_all_game_list *game,
			double x, float y, float line_texture);
int		print_e_t_line(t_all_game_list *game, double x, float y, float line_text);
int		print_w_t_line(t_all_game_list *game, double x, float y, float line_text);
int		print_s_t_line(t_all_game_list *game,
			double x, float y, float line_text);
int		visable_sprite_oy(t_map_list *map,
			t_list_main_hero_management *hero, double h, t_all_game_list *game);
int		npc_map_parser(t_map_list *map);
int		rendering_sprite(t_win_list *win, t_map_list *map, t_list_item *sprite);
int		sprite_printing(t_win_list *win, t_map_list *map);
int		sort_sprite(t_map_list *map);
int		reset_to_zero_sprite(t_map_list *map);
int		end_game(t_all_game_list *game);
int		gr(t_map_list *map, int fd);
int		moving_main_hero_plus(t_all_game_list *game);
int		create_screenshot(t_all_game_list *game);
void	revers(char *a);
size_t	ft_strlen(const char *s);
void	ft_lstadd_back(t_list_item **lst, t_list_item *new);
void	my_mlx_pixel_put(t_win_list *win, int x, int y, int color);
int		my_mlx_pixel_get(t_win_list *win, int x, int y);
void	my_mlx_pixel_put_3d(t_win_list *win, int x, int y, int color);
void	my_mlx_pixel_put_n_t(t_n_t *north, int x, int y, int color);
void	my_mlx_pixel_put_3d_texture(t_win_list *win, int x, int y, int color);
void	ft_bzero(void *s, size_t n);
int		my_mlx_pixel_get_3d(t_win_list *win, int x, int y);



#endif
