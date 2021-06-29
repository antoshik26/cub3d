/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_like_compass.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:48:47 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 21:52:33 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	print_n_t_line(t_all_game_list *game, double x, float y, float line_text)
{
	double	i;
	float	h2;
	double	a;
	double	b;

	i = x;
	h2 = game->line->h_wall / 128;
	while (i < game->line->h_wall)
	{
		a = ((int)(line_text * game->map->n_t->kef_n_t_w * h2));
		a = a * (game->map->n_t->n_t_b / 8);
		b = ((int)((i - x) * game->map->n_t->kef_n_t_h * h2));
		b = b * game->map->n_t->n_t_l;
		a = a + b;
		my_mlx_pixel_put_3d(game->win, y, i,
			*(unsigned int *)(game->map->n_t->addr_n_t + (int)a));
		i++;
	}
	return (0);
}

int	print_e_t_line(t_all_game_list *game, double x, float y, float line_text)
{
	double	i;
	float	h2;
	double	a;
	double	b;

	i = x;
	h2 = game->line->h_wall / 128;
	while (i < game->line->h_wall)
	{
		a = ((int)(line_text * game->map->e_t->kef_e_t_heiht * h2));
		a = a * (game->map->e_t->e_t_b / 8);
		b = ((int)((i - x) * game->map->e_t->kef_e_t_w * h2));
		b = b * game->map->e_t->e_t_l;
		a = a + b;
		my_mlx_pixel_put_3d(game->win, y, i,
			*(unsigned int *)(game->map->e_t->addr_e_t + (int)a));
		i++;
	}
	return (0);
}

int	print_w_t_line(t_all_game_list *game, double x, float y, float line_text)
{
	double	i;
	float	h2;
	double	a;
	double	b;

	i = x;
	h2 = game->line->h_wall / 128;
	while (i < game->line->h_wall)
	{
		a = ((int)(line_text * game->map->w_t->kef_w_t_h * h2));
		a = a * (game->map->w_t->w_t_b / 8);
		b = ((int)((i - x) * game->map->w_t->kef_w_t_w * h2));
		b = b * game->map->w_t->w_t_l;
		a = a + b;
		my_mlx_pixel_put_3d(game->win, y, i,
			*(unsigned int *)(game->map->w_t->addr_w_t + (int)a));
		i++;
	}
	return (0);
}

int	print_s_t_line(t_all_game_list *game, double x, float y, float line_text)
{
	double	i;
	float	h2;
	double	a;
	double	b;

	i = x;
	h2 = game->line->h_wall / 128;
	while (i < game->line->h_wall)
	{
		a = ((int)(line_text * game->map->s_t->kef_s_t_h * h2));
		a = a * (game->map->s_t->s_t_b / 8);
		b = ((int)((i - x) * game->map->s_t->kef_s_t_w * h2));
		b = b * game->map->s_t->s_t_l;
		a = a + b;
		my_mlx_pixel_put_3d(game->win, y, i,
			*(unsigned int *)(game->map->s_t->addr_s_t + (int)a));
		i++;
	}
	return (0);
}
