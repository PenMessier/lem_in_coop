/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:37:01 by frenna            #+#    #+#             */
/*   Updated: 2020/02/27 20:25:57 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int		dfs(int v, int flow, t_meta *dub)
{
	int	to;
  int	pushed;

  if (!flow)
		return (0);
  if (v == dub->t)
		return (flow);
  to = dub->ptr[v];
	while (to < dub->room_count)
	{
		to++;
		if (dub->d[to] != dub->d[v] + 1)
			continue;
		pushed = dfs(to, imin(flow, dub->c[v * dub->room_count + to] - dub->f[v * dub->room_count + to]), dub);
		if (pushed)
		{
			dub->f[v * dub->room_count + to] += pushed;
			dub->f[to * dub->room_count + v] -= pushed;
			return (pushed);
		}
	}
	return (0);
}
