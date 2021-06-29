/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:14:18 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 17:02:18 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

t_win_list					g_win_manager;
t_map_list					g_map;
t_list_main_hero_management	g_hero;
t_all_game_list				g_game;
t_list_mouse_manager		g_mouse;
t_list_key_moving			g_key;
t_line_list					g_line;
t_n_t						g_n_t;
t_s_t						g_s_t;
t_w_t						g_w_t;
t_e_t						g_e_t;
t_sp_t						g_sp_t;

int	gaming(t_all_game_list *game)
{
	create_pictures(game);
	moving_main_hero(game);
	changes_v_d(game);
	rendering_pictures(game);
	destroy_image(game);
	return (0);
}

int	end_game(t_all_game_list *game)
{
	t_list_item	*sprite;
	t_list_item	*tmp;
	int			i;

	i = 0;
	sprite = game->map->sprite;
	tmp = game->map->sprite;
	while (sprite)
	{
		tmp = sprite;
		sprite = sprite->next;
		free(tmp);
	}
	i = 0;
	while (game->map->map[i])
	{
		free(game->map->map[i]);
		i++;
	}
	free (game->map->map);
	exit (EXIT_SUCCESS);
}

int	file_create_screenshot(t_all_game_list *game)
{
	create_pictures(game);
	moving_main_hero(game);
	painting_hero(game->win, game->hero);
	ray_calculation(game);
	sprite_printing(game->win, game->map);
	create_screenshot(game);
	destroy_image(game);
	end_game(game);
	return (0);
}

int	run_game(t_all_game_list *game, int argc, char *argv[])
{
	game->win->init = mlx_init();
	if (map_parser(game->map, game->win, argv[1]) == -1)
	{
		perror("ERROR\nMAP NO VALIDATION\n");
		end_game(game);
		return (-1);
	}
	if (argc == 3)
	{
		file_create_screenshot(game);
		return (0);
	}
	game->win->new_win_3d = mlx_new_window(game->win->init,
			game->map->width, game->map->height, "cub3d");
	mlx_hook(game->win->new_win_3d, 2, 1, check_key_button, game);
	mlx_key_hook(game->win->new_win_3d, key_realize, game);
	mlx_hook(game->win->new_win_3d, 17, 1, end_game, game);
	mlx_mouse_hook(game->win->new_win_3d, check_mouse_hook, game);
	mlx_mouse_move(game->win->new_win_3d, game->map->height / 2,
		game->map->width / 2);
	mlx_loop_hook(game->win->init, gaming, game);
	mlx_loop(game->win->init);
	return (0);
}

int	main(int argc, char *argv[])
{
	g_map.n_t = &g_n_t;
	g_map.s_t = &g_s_t;
	g_map.w_t = &g_w_t;
	g_map.e_t = &g_e_t;
	g_map.sp_t = &g_sp_t;
	g_game.win = &g_win_manager;
	g_game.map = &g_map;
	g_game.hero = &g_hero;
	g_game.hero->key_press = &g_key;
	g_game.hero->mouse_manager = &g_mouse;
	g_game.line = &g_line;
	if (argc > 3)
	{
		perror("ERROR\nTOO MANY ARGUMENTS\n");
		return (0);
	}
	if (argc < 2)
	{
		perror("ERROR\nNOT ENOUGH ARGUMENTS\n");
		return (0);
	}
	run_game(&g_game, argc, argv);
	return (0);
}
