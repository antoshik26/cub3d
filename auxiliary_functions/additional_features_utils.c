/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_features_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:54:32 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 18:20:09 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

void	hezx(unsigned int b, char *hex)
{
	int				i;
	unsigned int	c;

	i = 0;
	while (b > 0)
	{
		c = b % 16;
		if (c < 10)
			hex[i] = c + '0';
		else
			hex[i] = (c - 10) + 'A';
		b = b / 16;
		i++;
	}
}

int	len_hex(unsigned int b)
{
	int	i;

	i = 0;
	while (b > 0)
	{
		i++;
		b = b / 16;
	}
	return (i);
}

int	len_hex_void(long long int b)
{
	int	i;

	i = 0;
	while (b > 0)
	{
		i++;
		b = b / 16;
	}
	return (i);
}

void	hemx_void(long long int b, char *hex)
{
	int				i;
	unsigned int	c;

	i = 0;
	while (b > 0)
	{
		c = b % 16;
		if (c < 10)
			hex[i] = c + '0';
		else
			hex[i] = (c - 10) + 'a';
		b = b / 16;
		i++;
	}
}

void	hemx(unsigned int b, char *hex)
{
	int				i;
	unsigned int	c;

	i = 0;
	while (b > 0)
	{
		c = b % 16;
		if (c < 10)
			hex[i] = c + '0';
		else
			hex[i] = (c - 10) + 'a';
		b = b / 16;
		i++;
	}
}
