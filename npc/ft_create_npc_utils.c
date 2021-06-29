/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_npc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 00:33:41 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 17:03:43 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	visable_sprite_oy_utils(t_map_list *map, t_list_main_hero_management *hero,
		t_list_item *sp, t_all_game_list *game)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;

	a = sp->distance_from_the_player;
	b = (((double)hero->v_d) / 180.0 * 3.14);
	c = (sp->a - b) / (3.14 / 3.0) * ((double)map->width);
	c = c + ((double)map->width) / 2;
	d = c - sp->sprite_size * (-2 * (sp->a - b));
	c = c + sp->sprite_size * (0.5 * (sp->a - b));
	sp->sprite_size = (double)map->width / a;
	e = (map->height - (map->height / a)) / 2;
	sp->v_offset = e + sp->sprite_size / 2.0;
	if (b <= game->line->a)
		sp->h_offset = c;
	else
		sp->h_offset = d;
	return (0);
}

int	visable_sprite_oy(t_map_list *map, t_list_main_hero_management *hero,
		double h, t_all_game_list *game)
{
	t_list_item	*sp;

	sp = map->sprite;
	while (sp)
	{
		if (sp->x == (int)(game->line->y / 32) && \
				sp->y == (int)(game->line->x / 32) && \
				sp->visable != 1 && sp->key == 0)
		{
			sp->visable = 1;
			sp->distance_from_the_player = h / 32;
			sp->h = h;
			sp->a = game->line->a;
			visable_sprite_oy_utils(map, hero, sp, game);
		}
		sp = sp->next;
	}
	return (0);
}

int	sort_sprite_utils(t_list_item *new_root,
		t_list_item *node, t_list_item *current)
{
	current = new_root;
	while (current->next != NULL && !(node->h > current->next->h))
		current = current->next;
	node->next = current->next;
	current->next = node;
	return (0);
}

int	sort_sprite(t_map_list *map)
{
	t_list_item	*sprite;
	t_list_item	*new_root;
	t_list_item	*node;
	t_list_item	*current;

	new_root = NULL;
	sprite = map->sprite;
	current = NULL;
	while (sprite)
	{
		node = sprite;
		sprite = sprite->next;
		if (new_root == NULL || node->h > new_root->h)
		{
			node->next = new_root;
			new_root = node;
		}
		else
			sort_sprite_utils(new_root, node, current);
	}
	map->sprite = new_root;
	return (0);
}

int	reset_to_zero_sprite(t_map_list *map)
{
	t_list_item	*sprite;

	sprite = map->sprite;
	while (sprite)
	{
		sprite->h = 0;
		sprite->key = 0;
		sprite->a = 0;
		sprite->visable = 0;
		sprite->h_offset = -10000000;
		sprite->v_offset = -10000000;
		sprite = sprite->next;
	}
	return (0);
}
