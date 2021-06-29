/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_features_utils_more_plus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:19:15 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 18:19:18 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

void	my_mlx_pixel_put(t_win_list *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_3d(t_win_list *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr_3d + (y * win->line_length_3d +\
			x * (win->bits_per_pixel_3d / 8));
	*(unsigned int *)dst = color;
}
