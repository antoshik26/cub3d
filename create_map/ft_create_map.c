/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:27:35 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 20:41:55 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	create_map(t_win_list *win, t_map_list *map,
		t_list_main_hero_management *hero)
{
	int	i;
	int	j;

	i = 0;
	while (map->p_f[i])
	{
		j = 0;
		while (map->p_f[i][j])
		{
			if (map->p_f[i][j] == '1')
				if (create_wall(win, i, j) == -1)
					return (-1);
			if (map->p_f[i][j] == '2')
				if (create_item(win, i, j) == -1)
					return (-1);
			if (map->p_f[i][j] == 'N' || map->p_f[i][j] == 'W'
			|| map->p_f[i][j] == 'E' || map->p_f[i][j] == 'S')
				if (create_hero(map, hero, i, j) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	create_wall(t_win_list *win, int i, int j)
{
	int	k;
	int	z;

	k = 0;
	while (k < 32)
	{
		z = 0;
		while (z < 32)
		{
			my_mlx_pixel_put(win, ((j * 32) + z), ((i * 32) + k), 0x00FF0000);
			z++;
		}
		k++;
	}
	return (0);
}

int	create_item(t_win_list *win, int i, int j)
{
	int	k;
	int	z;

	k = 0;
	while (k < 10)
	{
		z = 0;
		while (z < 10)
		{
			my_mlx_pixel_put(win, ((j * 32) + z), ((i * 32) + k), 0x00000FF0);
			z++;
		}
		k++;
	}
	return (0);
}
