/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodewae.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:29:37 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 14:07:11 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	tf_dewae(t_meta *all, int *wae, int *num)
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

static int	ft_wae_max(int n, int *wae, int flow)
{
	int		i;
	int		j;
	int		k;
	int		max;

	i = 0;
	max = 0;
	while (i < flow)
	{
		j = 0;
		k = 0;
		while (j < n)
		{
			if (wae[i * n + j] != -1)
				k++;
			j++;
		}
		if (max < k)
			max = k;
		i++;
	}
	return (max);
}

int			ft_nodewae(t_meta *all, int *wae, int flow)
{
	int		num[5];

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
	return (ft_wae_max(all->n, wae, flow));
}
