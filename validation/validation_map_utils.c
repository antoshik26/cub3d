/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:50:08 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 20:06:27 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	validation_p_f_first(t_map_list *map)
{
	int	key;
	int	i;
	int	j;

	i = 0;
	j = 0;
	key = 1;
	while (map->p_f[i][j])
	{
		if (map->p_f[i][j] != '1')
			key = 0;
		j++;
	}
	return (key);
}

int	validation_p_f_last(t_map_list *map, int k)
{
	int	key;
	int	i;
	int	j;

	i = k;
	j = 0;
	key = 1;
	while (map->p_f[i][j])
	{
		if (map->p_f[i][j] != '1')
			key = 0;
		j++;
	}
	return (key);
}

int	validation_p_f_between(t_map_list *map, int i, int *j)
{
	int	key;

	key = 1;
	while (map->p_f[i][*j] == ' ')
		*j = *j + 1;
	if (map->p_f[i][*j] != '1')
		key = 0;
	return (key);
}

int	salidation_simvol_in_map(t_map_list *map)
{
	int		i;
	int		j;
	char	b;
	int		key;

	key = 1;
	i = 0;
	j = 0;
	while (map->p_f[i])
	{
		j = 0;
		while (map->p_f[i][j])
		{
			b = map->p_f[i][j];
			if (b != '1' && b != '0' && b != 'S' && b != 'N' && b != 'E' &&\
					b != 'W' && b != '2' && b != ' ')
				key = 0;
			if (map->p_f[i][j] == ' ')
				key = validation_p_f_between(map, i, &j);
			j++;
		}
		i++;
	}
	return (key);
}

int	validation_p_f(t_map_list *map)
{
	int	i;
	int	k;
	int	key;

	key = 1;
	i = 0;
	k = 0;
	while (map->p_f[k])
		k++;
	while (map->p_f[i])
	{
		if (i == 0)
			key = validation_p_f_first(map);
		if (i == (k - 1))
			key = validation_p_f_last(map, (k - 1));
		i++;
		if (key == 0)
			return (-1);
	}
	key = salidation_simvol_in_map(map);
	if (key == 0)
		return (-1);
	return (0);
}
