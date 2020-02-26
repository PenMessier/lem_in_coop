/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:30 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:18:20 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void input(t_meta *all, int maxn)
{
	int     *c;
	int     *f;
	int     *d;
    int     *ptr;
    int     *q;
	int		i;
    int		j;

	all->s = 0;
	all->t = 5;
	all->n = maxn;
	all-> maxn = maxn;
	c = (int*)malloc(maxn * maxn * sizeof(int));
	f = (int*)malloc(maxn * maxn * sizeof(int));
	d = (int*)malloc(maxn * sizeof(int));
	q = (int*)malloc(maxn * sizeof(int));
	ptr = (int*)malloc(maxn * sizeof(int));
	all->c = c;
	all->f = f;
	all->d = d;
	all->ptr = ptr;
	all->q = q;
	for(i = 0; i < maxn; i++){
        for (j = 0; j < maxn; j++){
			c[i * maxn + j] = 0;
			f[i * maxn + j] = 0;
        }
    }
	c[0 * maxn + 1] = 1;  c[1 * maxn + 0] = 1;
	c[0 * maxn + 2] = 1;  c[2 * maxn + 0] = 1;
	c[1 * maxn + 3] = 1;  c[3 * maxn + 1] = 1;
	c[2 * maxn + 3] = 1;  c[3 * maxn + 2] = 1;
	c[2 * maxn + 4] = 1;  c[4 * maxn + 2] = 1;
	c[3 * maxn + 5] = 1;  c[5 * maxn + 3] = 1;
	c[4 * maxn + 5] = 1;  c[5 * maxn + 4] = 1;
/*	c[0 * maxn + 1] = 1;  c[1 * maxn + 0] = 1;
	c[0 * maxn + 2] = 1;  c[2 * maxn + 0] = 1;
	c[1 * maxn + 3] = 1;  c[3 * maxn + 1] = 1;
	c[2 * maxn + 3] = 1;  c[3 * maxn + 2] = 1;
	c[3 * maxn + 4] = 1;  c[4 * maxn + 3] = 1;
	c[3 * maxn + 5] = 1;  c[5 * maxn + 3] = 1;
	c[4 * maxn + 6] = 1;  c[6 * maxn + 4] = 1;
	c[6 * maxn + 5] = 1;  c[5 * maxn + 6] = 1;*/
}
