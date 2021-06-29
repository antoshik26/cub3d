/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_collor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:55:31 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 01:58:47 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	create_celling_collor(t_map_list *map)
{
	int	i;
	int	j;
	int	collor;

	j = 0;
	if (map->map[9][0] != 'C')
		return (-1);
	i = 2;
	while (j < 3)
	{
		if (map->map[9][i] == ',')
			i++;
		collor = 0;
		while (map->map[9][i] >= '0' && map->map[9][i] <= '9')
		{
			collor = (collor * 10) + (map->map[9][i] - '0');
			i++;
		}
		if (collor > 225)
			return (-1);
		map->floor_color[j] = collor;
		j++;
	}
	return (0);
}

int	create_floor_collor(t_map_list *map)
{
	int	i;
	int	j;
	int	collor;

	j = 0;
	if (map->map[8][0] != 'F')
		return (-1);
	i = 2;
	while (j < 3)
	{
		if (map->map[8][i] == ',')
			i++;
		collor = 0;
		while (map->map[8][i] >= '0' && map->map[8][i] <= '9')
		{
			collor = (collor * 10) + (map->map[8][i] - '0');
			i++;
		}
		if (collor > 255)
			return (-1);
		map->ceilling_color[j] = collor;
		j++;
	}
	return (0);
}

int	create_celling_collor_ox(t_map_list *map)
{
	int	rgb;

	rgb = map->ceilling_color[0];
	rgb = (rgb << 8) + map->ceilling_color[1];
	rgb = (rgb << 8) + map->ceilling_color[2];
	map->ceilling_color_ox = rgb;
	return (0);
}

int	crete_floor_color_xo(t_map_list *map)
{
	int	rgb;

	rgb = map->floor_color[0];
	rgb = (rgb << 8) + map->floor_color[1];
	rgb = (rgb << 8) + map->floor_color[2];
	map->floor_collor_ox = rgb;
	return (0);
}
