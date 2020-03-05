/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:36:52 by frenna            #+#    #+#             */
/*   Updated: 2020/03/03 13:38:44 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int     bfs(t_meta *dub)
{
	int 	to;
	int 	qh;
	int 	qt;
	int 	v;

	qh = 0;
	qt = 0;
	dub->q[qt++] = dub->s;
	ft_memset(dub->d, -1, dub->room_count * sizeof(dub->d[0]));
	dub->d[dub->s] = 0;
	while (qh < qt)
	{
		v = dub->q[qh++];
		to = 0;
		while (to < dub->room_count)
		{
			++to;
			if (dub->d[to] == -1 &&
			dub->f[v * dub->room_count + to] < dub->c[v * dub->room_count + to])
			{
				dub->q[qt++] = to;
				dub->d[to] = dub->d[v] + 1;
			}
		}
	}
	return (dub->d[dub->t] != -1);
}
