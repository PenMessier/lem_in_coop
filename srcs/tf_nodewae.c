/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_nodewae.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:29:37 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 13:24:59 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	tf_dewae(t_meta *all, int *wae, int *num)
{
	num[2] = 0;
	while (num[2] < all->n)
	{
		if (all->f[num[2] * all->n + num[1]] == -1)
		{
			wae[num[3] * all->n + num[4]] = num[2];
			num[4]++;
			num[1] = num[2];
			break ;
		}
		num[2]++;
	}
}

void	tf_nodewae(t_meta *all, int *wae, int flow)
{
	int num[5];

	num[0] = 0;
	num[3] = 0;
	while (num[0] < all->n && num[3] < flow)
	{
		num[4] = 2;
		if (all->f[num[0] * all->n + all->s] == -1)
		{
			if (wae[0] != -1)
				num[3]++;
			wae[num[3] * all->n] = all->s;
			wae[num[3] * all->n + 1] = num[0];
			num[1] = num[0];
			while (num[1] != all->t)
				tf_dewae(all, wae, num);
		}
		num[0]++;
	}
}
