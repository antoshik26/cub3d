/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maint_hero_muvment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 04:25:34 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 04:57:27 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	moving_main_hero_forvard(t_all_game_list *game)
{
	int		color;
	double	a;
	double	b;

	if (game->hero->key_press->forvard == 1)
	{
		color = my_mlx_pixel_get(game->win,
				game->hero->y + 3 * sin((game->hero->v_d) / 180 * 3.14),
				game->hero->x + 3 * cos((game->hero->v_d) / 180 * 3.14));
		if (color == 0x00000000)
		{
			a = cos((game->hero->v_d) / 180 * 3.14);
			b = sin((game->hero->v_d) / 180 * 3.14);
			game->hero->x = game->hero->x + (2 * a);
			game->hero->y = game->hero->y + (2 * b);
		}
	}
	return (0);
}

int	moving_main_hero_backward(t_all_game_list *game)
{
	int		color;
	double	a;
	double	b;

	if (game->hero->key_press->backward == 1)
	{
		color = my_mlx_pixel_get(game->win,
				game->hero->y - 3 * sin((game->hero->v_d) / 180 * 3.14),
				game->hero->x - 3 * cos((game->hero->v_d) / 180 * 3.14));
		if (color == 0x00000000)
		{
			a = cos((game->hero->v_d) / 180 * 3.14);
			b = sin((game->hero->v_d) / 180 * 3.14);
			game->hero->x = game->hero->x - (2 * a);
			game->hero->y = game->hero->y - (2 * b);
		}
	}
	return (0);
}

int	moving_main_hero_left(t_all_game_list *game)
{
	int		color;
	double	a;
	double	b;

	if (game->hero->key_press->right == 1)
	{
		color = my_mlx_pixel_get(game->win,
				game->hero->y + 3 * cos((game->hero->v_d) / 180 * 3.14),
				game->hero->x - 3 * sin((game->hero->v_d) / 180 * 3.14));
		if (color == 0x00000000)
		{
			a = sin((game->hero->v_d) / 180 * 3.14);
			b = cos((game->hero->v_d) / 180 * 3.14);
			game->hero->x = game->hero->x - (2 * a);
			game->hero->y = game->hero->y + (2 * b);
		}
	}
	return (0);
}

int	moving_main_hero_right(t_all_game_list *game)
{
	int		color;
	double	a;
	double	b;

	if (game->hero->key_press->left == 1)
	{
		color = my_mlx_pixel_get(game->win,
				game->hero->y - 3 * cos((game->hero->v_d) / 180 * 3.14),
				game->hero->x + 3 * sin((game->hero->v_d) / 180 * 3.14));
		if (color == 0x00000000)
		{
			a = sin((game->hero->v_d) / 180 * 3.14);
			b = cos((game->hero->v_d) / 180 * 3.14);
			game->hero->x = game->hero->x + (2 * a);
			game->hero->y = game->hero->y - (2 * b);
		}
	}
	return (0);
}

int	moving_main_hero(t_all_game_list *game)
{
	moving_main_hero_forvard(game);
	moving_main_hero_backward(game);
	moving_main_hero_left(game);
	moving_main_hero_right(game);
	if (game->hero->v_d == 0 && game->hero->x == 0 && game->hero->y == 0)
		game->hero->v_d = game->hero->first_v_d;
	if ((game->hero->x == 0) || (game->hero->y == 0))
	{
		game->hero->x = game->hero->first_x;
		game->hero->y = game->hero->first_y;
	}
	painting_hero(game->win, game->hero);
	return (0);
}
