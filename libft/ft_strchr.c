/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:31:47 by dmadelei          #+#    #+#             */
/*   Updated: 2020/11/02 22:31:29 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char *)s;
	while (a[i] != '\0')
	{
		if (a[i] == c)
		{
			return (&a[i]);
		}
		i++;
	}
	if (c == '\0')
		return (&a[i]);
	return (NULL);
}