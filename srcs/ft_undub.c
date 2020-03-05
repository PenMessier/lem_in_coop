/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:10:29 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 13:20:14 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	ft_undub(t_meta *all, t_meta *dub)
{
	int	i;
	int	j;
	int	a;
	int	b;
	int	c;

	i = 0;
	while (i < all->n)
	{
		j = 0;
		while (j < all->n)
		{
			a = dub->f[i * dub->n * 2 + j * 2];
			b = dub->f[i * dub->n * 2 + j * 2 + 1];
			c = dub->f[i * dub->n * 2 + j * 2 + dub->n];
			all->f[i * all->n + j] = a + b + c +
				dub->f[i * dub->n * 2 + j * 2 + 1 + dub->n];
			j++;
		}
		i++;
	}
}

