/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:37:01 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:04:15 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int     dfs (int v, int flow, t_meta *all)
{
	int  to;
        int pushed;

        if (!flow)  return 0;
        if (v == all->t)  return flow;
        to=all->ptr[v];
	while (to<all->maxn)
	{
		to++;
		if (all->d[to] != all->d[v] + 1)  continue;
		pushed = dfs (to, imin(flow, all->c[v * all->maxn + to] - all->f[v * all->maxn + to]), all);
		if (pushed)
		{
			all->f[v * all->maxn + to] += pushed;
			all->f[to * all->maxn + v] -= pushed;
			return pushed;
		}
	}
	return 0;
}
