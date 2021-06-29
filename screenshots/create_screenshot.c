/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screenshot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:35:47 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 16:43:38 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

void	int_to_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)(i);
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

int	create_screenshot_data(int fd, t_all_game_list *game, int padsize)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	y = game->map->height - 1;
	ft_bzero(zero, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < game->map->width)
		{
			pixel = my_mlx_pixel_get_3d(game->win, x, y);
			if (write(fd, &pixel, 3) < 0)
				return (0);
			if (padsize > 0 && write (fd, &zero, padsize) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (0);
}

int	create_screenshot_header(int fd, int h, int w, int padsize)
{
	int				filesize;
	unsigned char	header[54];

	filesize = 54 + (w * 3 * h) + (padsize * h);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, w);
	int_to_char(header + 22, h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	if (write(fd, header, 54) < 0)
		return (-1);
	return (0);
}

int	create_screenshot(t_all_game_list *game)
{
	int	fd;
	int	padsize;

	padsize = (4 - ((int)game->map->width * 3) % 4) % 4;
	fd = open("screenshot.bmp", O_WRONLY | \
		O_CREAT, 0777 | O_TRUNC | O_APPEND);
	if (fd < 0)
		return (-1);
	create_screenshot_header(fd, game->map->height, game->map->width, padsize);
	create_screenshot_data(fd, game, padsize);
	close(fd);
	end_game(game);
	return (0);
}
