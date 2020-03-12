/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:46 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 12:31:10 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int     	dinic(t_meta *all)
{
	int		flow;
	int		pushed;
	t_meta	dub;
	
	flow = 0;
	ft_init_meta(&dub);
	if (!(ft_dub(all, &dub)))
		return (-1);
	while (bfs(&dub))
	{
		ft_memset((&dub)->ptr, 0, (&dub)->n * sizeof((&dub)->ptr[0]));
		while ((pushed = dfs((&dub)->s, 1234567890, &dub)))
			flow += pushed;
	}
	ft_undub(all, &dub);
	free_meta(&dub);
	return (flow);
}
