/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:16:24 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 01:27:15 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	parser_norse_texture(t_map_list *map, t_win_list *win)
{
	int	i;
	int	j;

	j = 3;
	i = -1;
	if (map->map[2][0] != 'N' && map->map[2][1] != 'O')
		return (-1);
	while (map->map[2][j])
		j++;
	map->n_t->path_n_t = (char *)malloc(sizeof(char) * (j + 1));
	if (map->n_t->path_n_t == NULL)
		return (-1);
	j = 2;
	while (map->map[2][j])
		map->n_t->path_n_t[i++] = map->map[2][j++];
	map->n_t->path_n_t[i] = '\0';
	map->n_t->n_t = mlx_xpm_file_to_image(win->init,
			map->n_t->path_n_t, &map->n_t->n_t_w, &map->n_t->n_t_h);
	if (map->n_t == NULL)
		return (-1);
	map->n_t->kef_n_t_w = (float)map->width / (float)map->n_t->n_t_w;
	map->n_t->kef_n_t_h = (float)map->height / (float)map->n_t->n_t_h;
	map->n_t->addr_n_t = mlx_get_data_addr(map->n_t->n_t, &map->n_t->n_t_b,
			&map->n_t->n_t_l, &map->n_t->n_t_e);
	return (0);
}

int	parser_s_t(t_map_list *map, t_win_list *win)
{
	int	i;
	int	j;

	j = 3;
	i = -1;
	if (map->map[3][0] != 'S' && map->map[3][1] != 'O')
		return (-1);
	while (map->map[3][j])
		j++;
	map->s_t->path_s_t = (char *)malloc(sizeof(char) * (j + 1));
	if (map->s_t->path_s_t == NULL)
		return (-1);
	j = 2;
	while (map->map[3][j])
		map->s_t->path_s_t[i++] = map->map[3][j++];
	map->s_t->path_s_t[i] = '\0';
	map->s_t->s_t = mlx_xpm_file_to_image(win->init,
			map->s_t->path_s_t, &map->s_t->s_t_w, &map->s_t->s_t_h);
	if (map->s_t == NULL)
		return (-1);
	map->s_t->kef_s_t_w = (float)map->width / (float)map->s_t->s_t_w;
	map->s_t->kef_s_t_h = (float)map->height / (float)map->s_t->s_t_h;
	map->s_t->addr_s_t = mlx_get_data_addr(map->s_t->s_t,
			&map->s_t->s_t_b, &map->s_t->s_t_l, &map->s_t->s_t_endian);
	return (0);
}

int	parser_w_t(t_map_list *map, t_win_list *win)
{
	int	i;
	int	j;

	j = 3;
	i = -1;
	if (map->map[4][0] != 'W' && map->map[4][1] != 'E')
		return (-1);
	while (map->map[4][j])
		j++;
	map->w_t->path_w_t = (char *)malloc(sizeof(char) * (j + 1));
	if (map->w_t->path_w_t == NULL)
		return (-1);
	j = 2;
	while (map->map[4][j])
		map->w_t->path_w_t[i++] = map->map[4][j++];
	map->w_t->path_w_t[i] = '\0';
	map->w_t->w_t = mlx_xpm_file_to_image(win->init,
			map->w_t->path_w_t, &map->w_t->w_t_w, &map->w_t->w_t_h);
	if (map->w_t == NULL)
		return (-1);
	map->w_t->kef_w_t_w = (float)map->width / (float)map->w_t->w_t_w;
	map->w_t->kef_w_t_h = (float)map->height / (float)map->w_t->w_t_h;
	map->w_t->addr_w_t = mlx_get_data_addr(map->w_t->w_t,
			&map->w_t->w_t_b, &map->w_t->w_t_l, &map->w_t->w_t_e);
	return (0);
}

int	parser_e_t(t_map_list *map, t_win_list *win)
{
	int	i;
	int	j;

	j = 3;
	i = -1;
	if (map->map[5][0] != 'E' && map->map[5][1] != 'A')
		return (-1);
	while (map->map[5][j])
		j++;
	map->e_t->path_e_t = (char *)malloc(sizeof(char) * (j + 1));
	if (map->e_t->path_e_t == NULL)
		return (-1);
	j = 2;
	while (map->map[5][j])
		map->e_t->path_e_t[i++] = map->map[5][j++];
	map->e_t->path_e_t[i] = '\0';
	map->e_t->e_t = mlx_xpm_file_to_image(win->init,
			map->e_t->path_e_t, &map->e_t->e_t_w, &map->e_t->e_t_h);
	if (map->e_t->e_t == NULL)
		return (-1);
	map->e_t->kef_e_t_w = (float)map->width / (float)map->e_t->e_t_w;
	map->e_t->kef_e_t_heiht = (float)map->height / (float)map->e_t->e_t_h;
	map->e_t->addr_e_t = mlx_get_data_addr(map->e_t->e_t,
			&map->e_t->e_t_b, &map->e_t->e_t_l, &map->e_t->e_t_e);
	return (0);
}

int	parser_sp_t(t_map_list *map, t_win_list *win)
{
	int	i;
	int	j;

	j = 2;
	i = -1;
	if (map->map[7][0] != 'S')
		return (-1);
	while (map->map[7][j])
		j++;
	map->sp_t->path_sp_t = (char *)malloc(sizeof(char) * (j + 1));
	if (map->sp_t->path_sp_t == NULL)
		return (0);
	j = 1;
	while (map->map[7][j])
		map->sp_t->path_sp_t[i++] = map->map[7][j++];
	map->sp_t->path_sp_t[i] = '\0';
	map->sp_t->sp_t = mlx_xpm_file_to_image(win->init,
			map->sp_t->path_sp_t, &(map->sp_t->sp_t_w), &(map->sp_t->sp_t_h));
	if (map->sp_t->sp_t == NULL)
		return (-1);
	map->sp_t->kef_sp_t_w = (float)map->width / (float)map->sp_t->sp_t_w;
	map->sp_t->kef_sp_t_h = (float)map->height / (float)map->sp_t->sp_t_h;
	map->sp_t->addr_sp_t = mlx_get_data_addr(map->sp_t->sp_t,
			&map->sp_t->sp_t_b, &map->sp_t->sp_t_l, &map->sp_t->sp_t_e);
	return (0);
}
