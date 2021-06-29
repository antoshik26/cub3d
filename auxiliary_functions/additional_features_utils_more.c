/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_features_utils_more.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:19:09 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 18:19:12 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

void	my_mlx_pixel_put_3d_texture(t_win_list *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr_3d + (y * win->line_length_3d +\
			x * (win->bits_per_pixel_3d / 8));
	if (color != 16777215)
	{
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_pixel_put_n_t(t_n_t *north, int x, int y, int color)
{
	char	*dst;

	dst = north->addr_n_t + (y * north->n_t_l +\
			x * (north->n_t_b / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_win_list *win, int x, int y)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	my_mlx_pixel_get_3d(t_win_list *win, int x, int y)
{
	char	*dst;

	dst = win->addr_3d + (y * win->line_length_3d +\
			x * (win->bits_per_pixel_3d / 8));
	return (*(unsigned int *)dst);
}

void	ft_lstadd_back(t_list_item **lst, t_list_item *new)
{
	t_list_item	*a;

	a = *lst;
	if (!*lst && new)
	{
		*lst = new;
	}
	while (a)
	{
		if (a->next == NULL)
		{
			a->next = new;
			break ;
		}
		else
			a = a->next;
	}
}
