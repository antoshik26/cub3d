/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:50:31 by dmadelei          #+#    #+#             */
/*   Updated: 2020/11/02 13:52:20 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' & c <= '9') ||
			((c >= 'A' & c <= 'Z') || (c >= 'a' & c <= 'z')))
		return (1);
	else
		return (0);
}