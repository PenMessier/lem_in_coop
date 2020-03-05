/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:37:01 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 13:20:46 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int		dfs(int v, int flow, t_meta *dub)
{
	int	pushed;
	int	to;

	if (!flow)
		return (0);
	if (v == dub->t)
		return (flow);
	to = dub->ptr[v];
	while (to < dub->n)
	{
		++to;
		if (dub->d[to] != dub->d[v] + 1)
			continue;
		pushed = dfs(to, imin(flow, dub->c[v * dub->n + to] -
			dub->f[v * dub->n + to]), dub);
		if (pushed)
		{
			dub->f[v * dub->n + to] += pushed;
			dub->f[to * dub->n + v] -= pushed;
			return (pushed);
		}
	}
	return (0);
}
