/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 03:11:38 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 03:20:37 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	gr(t_map_list *map, int fd);

int	map_parser(t_map_list *map, t_win_list *win, char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR\nNo open file with map\n");
		return (-1);
	}
	gr(map, fd);
	parser_screen_resolution(map);
	parser_texure(map, win);
	parser_color(map);
	parsing_p_f(map);
	map->sprite = NULL;
	npc_map_parser(map);
	crete_floor_color_xo(map);
	create_celling_collor_ox(map);
	if (validation_map(map) == -1)
	{
		perror ("ERROR\nMap no validation");
		return (-1);
	}
	return (0);
}

int	parser_screen_resolution(t_map_list *map)
{
	int	i;

	map->height = 0;
	map->width = 0;
	if (map->map[0][0] != 'R')
		return (-1);
	i = 2;
	while (map->map[0][i] >= '0' && map->map[0][i] <= '9')
	{
		map->width = (map->width * 10) + (map->map[0][i] - '0');
		i++;
	}
	if (map->map[0][i] != ' ')
		return (-1);
	i++;
	while (map->map[0][i] >= '0' && map->map[0][i] <= '9')
	{
		map->height = (map->height * 10) + (map->map[0][i] -'0');
		i++;
	}
	return (0);
}

int	parser_texure(t_map_list *map, t_win_list *win)
{
	parser_norse_texture(map, win);
	parser_s_t(map, win);
	parser_w_t(map, win);
	parser_e_t(map, win);
	parser_sp_t(map, win);
	return (0);
}

int	parser_color(t_map_list *map)
{
	create_celling_collor(map);
	create_floor_collor(map);
	create_celling_collor_ox(map);
	crete_floor_color_xo(map);
	return (0);
}

int	parsing_p_f(t_map_list *map)
{
	int	i;
	int	j;

	i = 11;
	j = 0;
	while (map->map[i])
		i++;
	map->p_f = (char **)malloc(sizeof(char *) * (i + 1));
	if (map->p_f == NULL)
		return (-1);
	i = 11;
	while (map->map[i])
	{
		map->p_f[j] = map->map[i];
		i++;
		j++;
	}
	map->p_f[j] = NULL;
	return (0);
}
