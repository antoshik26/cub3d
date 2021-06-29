/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_features.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:41:11 by dmadelei          #+#    #+#             */
/*   Updated: 2021/04/17 18:20:39 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_header.h"

int	len_uint(unsigned int a)
{
	int	n;

	n = 0;
	while (a > 0)
	{
		a = a / 10;
		n++;
	}
	return (n);
}

void	revers(char *a)
{
	int		i;
	int		len;
	char	b;

	i = 0;
	len = ft_strlen(a);
	while (i < (len / 2))
	{
		b = a[i];
		a[i] = a[(len - 1) - i];
		a[(len - 1) - i] = b;
		i++;
	}
}

void	print_precision(int *len_print, int len, char b, int *n)
{
	while (*len_print > len)
	{
		write(1, &b, 1);
		*n = *n + 1;
		*len_print = *len_print - 1;
	}
}

void	print_text(int *len_print, char *text, int *n)
{
	while (*len_print > 0)
	{
		write(1, text, 1);
		text++;
		*len_print = *len_print - 1;
		*n = *n + 1;
	}
}
