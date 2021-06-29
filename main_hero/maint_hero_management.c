/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maint_hero_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 04:57:34 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 20:07:53 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	check_key_button(int key, t_all_game_list *game)
{
	if (key == LEFT)
		game->hero->key_press->left = 1;
	if (key == RIGHT)
		game->hero->key_press->right = 1;
	if (key == BACKWARD)
		game->hero->key_press->backward = 1;
	if (key == FORWARD)
		game->hero->key_press->forvard = 1;
	if (key == LEFTROT)
		game->hero->key_press->leftrot = 1;
	if (key == RIGHTROT)
		game->hero->key_press->rightrot = 1;
	if (key == ESC)
		end_game(game);
	return (0);
}

int	key_realize(int key, t_all_game_list *game)
{
	if (key == LEFT)
		game->hero->key_press->left = 0;
	if (key == RIGHT)
		game->hero->key_press->right = 0;
	if (key == BACKWARD)
		game->hero->key_press->backward = 0;
	if (key == FORWARD)
		game->hero->key_press->forvard = 0;
	if (key == LEFTROT)
		game->hero->key_press->leftrot = 0;
	if (key == RIGHTROT)
		game->hero->key_press->rightrot = 0;
	return (0);
}

int	check_mouse_hook(int mousecode, t_all_game_list *game)
{
	if (mousecode == REGHT_CLICK_MOUSE)
		game->hero->mouse_manager->right_click_mouse = 1;
	if (mousecode == LEFT_CLICK_MOUSE)
		game->hero->mouse_manager->left_click_mouse = 1;
	return (0);
}

int	changes_v_d_key(t_all_game_list *game)
{
	if (game->hero->key_press->rightrot == 1)
	{
		game->hero->v_d = game->hero->v_d + 1;
	}
	if (game->hero->key_press->leftrot == 1)
	{
		game->hero->v_d = game->hero->v_d - 1;
	}
	return (0);
}

int	changes_v_d(t_all_game_list *game)
{
	int		x;
	int		y;
	double	a;
	double	b;

	game->hero->mouse_manager->central_x = game->map->height / 2;
	game->hero->mouse_manager->central_y = game->map->width /2;
	mlx_mouse_get_pos(game->win->new_win_3d, &x, &y);
	a = (game->hero->mouse_manager->central_x - x) / 100;
	b = (x - game->hero->mouse_manager->central_x) / 100;
	if (game->hero->mouse_manager->central_x != x)
	{
		if (game->hero->mouse_manager->central_x > x)
			game->hero->v_d = game->hero->v_d + a;
		else
			game->hero->v_d = game->hero->v_d - b;
	}
	changes_v_d_key(game);
	if (game->hero->v_d < -180)
		game->hero->v_d = 360 + (game->hero->v_d);
	if (game->hero->v_d > 180)
		game->hero->v_d = 0 + (game->hero->v_d - 360);
	mlx_mouse_move(game->win->new_win_3d,
		game->map->height / 2, game->map->width / 2);
	return (0);
}
