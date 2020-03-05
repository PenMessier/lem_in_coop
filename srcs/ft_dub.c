/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:57 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 13:18:55 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	ft_dub(t_meta *all, t_meta *dub)
{
	int	i;
	int	j;

	i = 0;
	dub->s = all->s * 2 + 1;
	dub->t = all->t * 2;
	dub->n = all->n * 2;
	dub->c = (int *)malloc(dub->n * dub->n * sizeof(int));
	dub->f = (int *)malloc(dub->n * dub->n * sizeof(int));
	dub->d = (int *)malloc(dub->n * sizeof(int));
	dub->q = (int *)malloc(dub->n * sizeof(int));
	dub->ptr = (int *)malloc(dub->n * sizeof(int));
	ft_memset(dub->c, 0, dub->n * dub->n * sizeof(int));
	ft_memset(dub->f, 0, dub->n * dub->n * sizeof(int));
	while (i < all->n)
	{
		j = 0;
		while (j < all->n)
		{
			if (all->c[i * all->n + j] == 1)
			{
				dub->c[(2 * i + 1) * dub->n + j * 2] = 1;
				dub->c[2 * i * dub->n + j * 2 + 1] = -1;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < dub->n)
	{
		if (i % 2 == 0)
			dub->c[i * dub->n + i + 1] = 1;
		if (i % 2 == 1)
			dub->c[i * dub->n + i - 1] = -1;
		i++;
	}
}
