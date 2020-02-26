/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:00:45 by frenna            #+#    #+#             */
/*   Updated: 2019/04/15 10:36:47 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		printarr(int *str, int i)
{
	if (str[0] == 1)
		ft_putchar('-');
	if (str[0] == 2)
	{
		ft_putchar('-');
		str[1] = str[1] + 1;
	}
	while (i > 0)
	{
		ft_putchar('0' + str[i]);
		i--;
	}
}

static	int		checknum(int nb, int *str)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			str[0] = 2;
			nb = -1 * (nb + 1);
		}
		else
		{
			str[0] = 1;
			nb *= -1;
		}
	}
	else
		str[0] = 0;
	return (nb);
}

void			ft_putnbr(int nb)
{
	int i;
	int str[11];

	i = 1;
	nb = checknum(nb, str);
	while (nb >= 10)
	{
		str[i] = nb % 10;
		nb /= 10;
		i++;
	}
	if (nb < 10)
		str[i] = nb;
	printarr(str, i);
}
