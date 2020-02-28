/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:57 by frenna            #+#    #+#             */
/*   Updated: 2020/02/27 20:17:45 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		ft_dub(t_meta *all, t_meta *dub)
{
	int     i;
	int     j;

	i = 0;
	dub->rooms = NULL;
	dub->links = NULL;
	dub->s = all->s * 2 + 1;
	dub->t = all->t * 2;
	dub->n = all->n * 2;
	dub->room_count = all->room_count * 2;
	dub->c = (int *)malloc(dub->room_count * dub->room_count * sizeof(int));
	dub->f = (int *)malloc(dub->room_count * dub->room_count * sizeof(int));
	dub->d = (int *)malloc(dub->room_count * sizeof(int));
	dub->q = (int *)malloc(dub->room_count * sizeof(int));
	dub->ptr = (int *)malloc(dub->room_count * sizeof(int));
	while (i < dub->room_count * dub->room_count)
	{
		dub->c[i] = 0;
		dub->f[i] = 0;
		i++;
	}
	i = 0;
	while (i < all->room_count)
	{
		j = 0;
		while (j < all->room_count)
		{
			if (all->c[i * all->room_count + j] == 1)
			{
				dub->c[(2 * i + 1) * dub->room_count + j * 2] = 1;
				dub->c[2 * i * dub->room_count + j * 2 + 1] = -1;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < dub->room_count)
	{
		if (i % 2 == 0)
			dub->c[i * dub->room_count + i + 1] = 1;
		if (i % 2 == 1)
			dub->c[i * dub->room_count + i - 1] = -1;
		i++;
	}
}
