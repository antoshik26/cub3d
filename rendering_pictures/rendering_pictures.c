/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_pictures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 03:26:51 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/15 03:31:42 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	destroy_image(t_all_game_list *game)
{
	mlx_destroy_image(game->win->init, game->win->pictures);
	mlx_destroy_image(game->win->init, game->win->pictures_3d);
	free(game->map->h_reicasting);
	return (0);
}

int	rendering_pictures(t_all_game_list *game)
{
	painting_hero(game->win, game->hero);
	ray_calculation(game);
	sprite_printing(game->win, game->map);
	mlx_put_image_to_window(game->win->init,
		game->win->new_win_3d, game->win->pictures_3d, 0, 0);
	return (0);
}

int	create_pictures(t_all_game_list *game)
{
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	game->win->pictures = mlx_new_image(game->win->init, 1920, 1080);
	game->win->addr = mlx_get_data_addr(game->win->pictures,
			&bits_per_pixel, &line_length, &endian);
	game->win->bits_per_pixel = bits_per_pixel;
	game->win->line_length = line_length;
	game->win->endian = endian;
	game->win->pictures_3d = mlx_new_image(game->win->init,
			game->map->width, game->map->height);
	game->win->addr_3d = mlx_get_data_addr(game->win->pictures_3d,
			&game->win->bits_per_pixel_3d,
			&game->win->line_length_3d, &game->win->endian_3d);
	if (create_map(game->win, game->map, game->hero) == -1)
	{
		end_game(game);
		return (-1);
	}
	return (0);
}
