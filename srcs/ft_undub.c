/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:10:29 by frenna            #+#    #+#             */
/*   Updated: 2020/02/28 14:24:05 by frenna           ###   ########.fr       */
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
	while (i < all->room_count)
	{
		j = 0;
		while (j < all->room_count)
		{
			a = dub->f[i * dub->room_count * 2 + j * 2];
			b = dub->f[i * dub->room_count * 2 + j * 2 + 1];
			c = dub->f[i * dub->room_count * 2 + j * 2 + dub->room_count];
			all->f[i * all->room_count + j] = a + b + c +
			dub->f[i * dub->room_count * 2 + j * 2 + 1 + dub->room_count];
			j++;
		}
		i++;
	}
}

