/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:31:53 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 03:10:53 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	gnl_reader_utils(t_map_list *map, char *line_map, char	**tmp, int k)
{
	int	j;

	j = 0;
	while (j < (k - 1))
	{
		map->map[j] = tmp[j];
		j++;
	}
	map->map[j] = line_map;
	j++;
	map->map[j] = NULL;
	return (0);
}

int	gr(t_map_list *map, int fd)
{
	char	*line_map;
	char	**tmp;
	int		i;
	int		k;
	int		j;

	i = 1;
	k = 0;
	while (i >= 0)
	{
		j = 0;
		i = get_next_line(fd, &line_map);
		tmp = map->map;
		k++;
		map->map = (char **)malloc(sizeof(char *) * k + 1);
		if (map->map == NULL)
			return (-1);
		gnl_reader_utils(map, line_map, tmp, k);
		free (tmp);
		if (i == 0)
			break ;
	}
	return (0);
}
