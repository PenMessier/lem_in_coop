/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_nodewae.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:29:37 by frenna            #+#    #+#             */
/*   Updated: 2020/02/28 14:31:59 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	tf_dewae(t_meta *all, int *wae, int *num)
{
	num[2] = 0;
	while (num[2] < all->room_count)
	{
		if (all->f[num[2] * all->room_count + num[1]] == -1)
		{
			wae[num[3] * all->room_count + num[4]] = num[2];
			num[4]++;
			num[1] = num[2];
			break ;
		}
		num[2]++;
	}
}

void	tf_nodewae(t_meta *all, int *wae, int nom)
{
	int num[5];

	num[0] = 0;
	num[3] = 0;
	while (num[0] < all->room_count && num[3] < nom)
	{
		num[4] = 2;
		if (all->f[num[0] * all->room_count + all->s] == -1)
		{
			if (wae[0] != -1)
				num[3]++;
			wae[num[3] * all->room_count] = all->s;
			wae[num[3] * all->room_count + 1] = num[0];
			num[1] = num[0];
			while (num[1] != all->t)
				tf_dewae(all, wae, num);
		}
		num[0]++;
	}
}
