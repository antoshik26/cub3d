/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_npc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:05:59 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 17:18:08 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	npc_map_initialization(t_list_item *sprite, int i, int j)
{
	sprite->x = i;
	sprite->y = j;
	sprite->h = 0;
	sprite->key = 0;
	sprite->a = 0;
	sprite->visable = 0;
	sprite->h_offset = -10000000;
	sprite->v_offset = -10000000;
	sprite->next = NULL;
	return (0);
}

int	npc_map_parser(t_map_list *map)
{
	int			i;
	int			j;
	t_list_item	*item;

	i = 0;
	j = 0;
	while (map->p_f[j])
	{
		i = 0;
		while (map->p_f[j][i])
		{
			if (map->p_f[j][i] == '2')
			{
				item = (t_list_item *)malloc(sizeof(t_list_item));
				npc_map_initialization(item, i, j);
				ft_lstadd_back(&map->sprite, item);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	sprite_printing(t_win_list *win, t_map_list *map)
{
	t_list_item	*sprite;

	sprite = map->sprite;
	while (sprite)
	{
		if (sprite->visable == 1)
		{
			sort_sprite(map);
			rendering_sprite(win, map, sprite);
		}
		sprite = sprite->next;
	}
	reset_to_zero_sprite(map);
	return (0);
}

int	rendering_sprite_utils(t_win_list *win, t_map_list *map,
		t_list_item *sprite, int i)
{
	int		j;
	double	a;
	double	b;

	j = 0;
	while (j < sprite->sprite_size)
	{
		if ((j + sprite->v_offset) > 0 && (j + sprite->v_offset < map->height))
		{
			a = (int)(j * map->sp_t->kef_sp_t_h);
			a = a * map->sp_t->sp_t_l;
			b = (int)(i * map->sp_t->kef_sp_t_w);
			b = b * (map->sp_t->sp_t_b / 8);
			a = a + b;
			my_mlx_pixel_put_3d_texture(win, sprite->h_offset + i,
				sprite->v_offset + j,
				*(unsigned int*)(map->sp_t->addr_sp_t + (int)a));
		}
		j++;
	}
	return (0);
}

int	rendering_sprite(t_win_list *win, t_map_list *map, t_list_item *sprite)
{
	int	i;
	int	j;

	map->sp_t->kef_sp_t_h = map->sp_t->sp_t_h / sprite->sprite_size;
	map->sp_t->kef_sp_t_w = map->sp_t->sp_t_w / sprite->sprite_size;
	j = 0;
	i = 0;
	while (i < sprite->sprite_size)
	{
		if (i + sprite->h_offset >= 0 && i + sprite->h_offset <= map->width)
		{
			if ((double)map->h_reicasting[(int)(i + sprite->h_offset)] >
					sprite->h - 10)
			{
				rendering_sprite_utils(win, map, sprite, i);
			}
		}
		i++;
	}
	return (0);
}
