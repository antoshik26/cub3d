/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:11:59 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 20:27:29 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	create_3d_map_line(t_all_game_list *game, double h, double j)
{
	h = (h / 124) * cos(game->line->a - ((double)game->hero->v_d / 180 * 3.14));
	create_3d_map_list_ceilling(game, h, j);
	create_3d_map_texture(game, h, j);
	create_3d_map_list_floor(game, h, j);
	return (0);
}

int	create_3d_map_list_floor(t_all_game_list *game, double h, double j)
{
	double	h_floor;
	int		k;

	k = 0;
	if (h > 1)
		h_floor = (game->map->height - (game->map->height / h)) / 2;
	else
		h_floor = 0;
	while (k < h_floor)
	{
		my_mlx_pixel_put_3d(game->win, j, k, game->map->floor_collor_ox);
		k++;
	}
	return (0);
}

int	create_3d_map_list_ceilling(t_all_game_list *game, double h, double j)
{
	double	h_ceilling;
	int		k;

	k = 0;
	if (h > 1)
		h_ceilling = (game->map->height - (game->map->height / h)) / 2;
	else
		h_ceilling = 0;
	while (k + h_ceilling < game->map->height)
	{
		my_mlx_pixel_put_3d(game->win, j,
			k + h_ceilling, game->map->ceilling_color_ox);
		k++;
	}
	return (0);
}

int	print_texture_wall_line(t_all_game_list *game,
		double k, double j, float line_texture)
{
	if (game->line->wall == NORTH)
		print_n_t_line(game, k, j, line_texture);
	if (game->line->wall == SOUTH)
		print_s_t_line(game, k, j, line_texture);
	if (game->line->wall == WEST)
		print_w_t_line(game, k, j, line_texture);
	if (game->line->wall == EAST)
		print_e_t_line(game, k, j, line_texture);
	return (0);
}

int	create_3d_map_texture(t_all_game_list *game, double h, double j)
{
	double	k;
	double	height_scy;
	float	line_texture;

	k = 0;
	line_texture = 0;
	if (h > 1)
	{
		height_scy = (game->map->height - (game->map->height / h)) / 2;
		k = k + height_scy;
		game->line->h_wall = (game->map->height / h) + height_scy;
	}
	else
	{
		height_scy = 0;
		k = k + height_scy;
		game->line->h_wall = game->map->height;
	}
	line_texture = where_did_raycasting_fall(game,
			game->line->x, game->line->y, game->line->wall);
	print_texture_wall_line(game, k, j, line_texture);
	return (0);
}
