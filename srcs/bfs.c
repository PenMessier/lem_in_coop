/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:36:52 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:04:15 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int     bfs(t_meta *all)
{
	int to;
    int qh=0;
    int qt=0;
    int v;

	all->q[qt++] = all->s;
	ft_memset (all->d, -1, all->n * sizeof all->d[0]);
	all->d[all->s] = 0;
	while (qh < qt)
	{
		v = all->q[qh++];
		to=0;
		while (to<all->maxn)
		{
			if (all->d[to] == -1 && all->f[v * all->maxn + to] < all->c[v * all->maxn + to])
			{
				all->q[qt++] = to;
				all->d[to] = all->d[v] + 1;
			}
			to++;
		}
	}
	return all->d[all->t] != -1;
}
