/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_her_management_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:21:02 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 16:30:21 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	create_hero(t_map_list *map,
		t_list_main_hero_management *hero, int i, int j)
{
	hero_position(map, hero, i, j);
	return (0);
}

void	hero_position(t_map_list *map,
		t_list_main_hero_management *hero, int i, int j)
{
	hero->first_x = i * 32;
	hero->first_y = j * 32;
	if (map->p_f[i][j] == 'N')
		hero->first_v_d = 180;
	if (map->p_f [i][j] == 'S')
		hero->first_v_d = 0;
	if (map->p_f[i][j] == 'W')
		hero->first_v_d = -90;
	if (map->p_f[i][j] == 'E')
		hero->first_v_d = 90;
	hero->live_main_hero = 2;
	hero->hp_main_hero = 100;
	hero->def_main_hero = 0;
}

void	painting_hero(t_win_list *win,
		t_list_main_hero_management *hero)
{
	my_mlx_pixel_put(win, hero->y, hero->x, 0x0000FFFF);
}

int	ray_calculation_utils(t_all_game_list *game, double *i)
{
	double	color;

	while (*i < 1920)
	{
		game->line->x = (game->hero->x) + *i * cos(game->line->a);
		color = my_mlx_pixel_get(game->win, game->line->y, game->line->x);
		if (color == 0x00FF0000)
		{
			game->line->wall = which_texture_print_ox(game->line->a);
			break ;
		}
		game->line->y = (game->hero->y) + *i * sin(game->line->a);
		color = my_mlx_pixel_get(game->win, game->line->y, game->line->x);
		if (color == 0x00FF0000)
		{
			game->line->wall = which_texture_print_oy(game->line->a);
			break ;
		}
		if (color != 0x00000FF0)
			my_mlx_pixel_put(game->win, game->line->y, game->line->x, CL);
		else
			visable_sprite_oy(game->map, game->hero, *i, game);
		*i = *i + 1;
	}
	return (0);
}

int	ray_calculation(t_all_game_list *game)
{
	double	i;
	int		j;

	i = 0;
	j = 0;
	game->map->h_reicasting = (int *)malloc(sizeof(int) * game->map->width);
	while (j < (double)game->map->width)
	{	
		game->line->a = ((game->hero->v_d) / 180 * 3.14) - \
			FOV / 2 + FOV * j / (double) game->map->width;
		i = 0;
		game->line->y = game->hero->y;
		ray_calculation_utils(game, &i);
		game->map->h_reicasting[j] = i;
		create_3d_map_line(game, i, j);
		j++;
	}
	return (0);
}
