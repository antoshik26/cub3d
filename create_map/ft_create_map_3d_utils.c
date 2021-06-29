/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_3d_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:26:47 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 20:43:22 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	which_texture_print_ox(double a)
{
	a = (a * 180) / 3.14;
	if (a > -90 && a < 90)
		return (SOUTH);
	else
		return (NORTH);
	return (0);
}

int	which_texture_print_oy(double a)
{
	a = (a * 180) / 3.14;
	if (a > 180)
		a = a - 360;
	if (a > 0)
		return (EAST);
	if (a < 0)
		return (WEST);
	return (0);
}

int	where_did_raycasting_fall(t_all_game_list *game,
		double x, double y, int wall)
{
	float	a;
	int		b;

	if (wall == WEST || wall == EAST)
	{
		a = x / 32;
		b = a;
		if (wall == WEST)
			a = (a - b) * game->map->w_t->w_t_w;
		else
			a = (a - b) * game->map->e_t->e_t_w;
		return ((int)a);
	}
	if (wall == NORTH || wall == SOUTH)
	{
		a = y / 32;
		b = a;
		if (wall == NORTH)
			a = (a - b) * game->map->n_t->n_t_w;
		else
			a = (a - b) * game->map->s_t->s_t_w;
		return ((int)a);
	}
	return (0);
}
