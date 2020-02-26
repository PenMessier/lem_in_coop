/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:57 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:04:15 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		ft_dub(t_meta *all, t_meta *dub)
{
	int		*c;
	int     *f;
	int     *d;
	int     *ptr;
	int     *q;
	int     i;
	int     j;

	dub->s = all->s * 2 + 1;
	dub->t = all->t * 2;
	dub->n = all->n * 2;
	dub->maxn = all->maxn * 2;
	c = (int*)malloc(all->maxn * 2 * all->maxn * 2 * sizeof(int));
	f = (int*)malloc(all->maxn * 2 * all->maxn * 2 * sizeof(int));
	d = (int*)malloc(all->maxn * 2 * sizeof(int));
	q = (int*)malloc(all->maxn * 2 * sizeof(int));
	ptr = (int*)malloc(all->maxn * 2 * sizeof(int));
	dub->c = c;
	dub->f = f;
	dub->d = d;
	dub->ptr = ptr;
	dub->q = q;
	for(i = 0; i < all->maxn * 2; i++){
                for (j = 0; j < all->maxn * 2; j++){
                        c[i * all->maxn * 2 + j] = 0;
                        f[i * all->maxn * 2 + j] = 0;
                }
        }
	for(i = 0; i < all->maxn; i++){
                for (j = 0; j < all->maxn; j++){
			if (all->c[i * all->maxn + j] == 1)
			{
				c[(2 * i + 1) * all->maxn * 2 + j * 2] = 1;
				c[(2 * i) * all->maxn * 2 + j * 2 + 1] = -1;
			}
                }
	}
	for(i = 0; i < all->maxn * 2; i++){
		if (i % 2 == 0)
			c[i *  2 * all->maxn + i + 1] = 1;
		if (i % 2 == 1)
			c[i *  2 * all->maxn + i - 1] = -1;
        }
}
