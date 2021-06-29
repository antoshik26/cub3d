/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:44:06 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 16:50:00 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	validation_map(t_map_list *map)
{
	validation_screen_extension(map);
	if (validation_image(map) == -1)
		return (-1);
	if (validation_p_f(map) == -1)
		return (-1);
	if (validatiom_collor(map) == -1)
		return (-1);
	return (0);
}

void	validation_screen_extension(t_map_list *map)
{
	if (map->width > 10000)
	{
		map->width = 1980;
	}
	if (map->height > 10000)
	{
		map->height = 1020;
	}
}

int	validation_image(t_map_list *map)
{
	if (map->n_t == NULL)
		return (-1);
	if (map->s_t == NULL)
		return (-1);
	if (map->w_t == NULL)
		return (-1);
	if (map->e_t == NULL)
		return (-1);
	if (map->sp_t == NULL)
		return (-1);
	return (0);
}

int	validatiom_collor(t_map_list *map)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (map->floor_color[i] > 255 && map->floor_color[i] != -1)
			return (-1);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (map->ceilling_color[i] > 255 && map->ceilling_color[i] != -1)
			return (-1);
		i++;
	}
	return (0);
}
