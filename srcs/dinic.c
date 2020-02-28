/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:46 by frenna            #+#    #+#             */
/*   Updated: 2020/02/28 15:02:26 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int     	dinic(t_meta *all)
{
	int		flow;
	int		pushed;
	t_meta	dub;
	
	flow = 0;
	init_meta(&dub);
	ft_dub(all, &dub);
	while(bfs(&dub))
	{
		ft_memset((&dub)->ptr, 0, (&dub)->room_count * sizeof(int));
		while ((pushed = dfs((&dub)->s, 1234567890, &dub)))
			flow += pushed;
	}
	ft_undub(all, &dub);
	printf("DUB3\n");
	ft_pr_f(&dub);
	printf("DUB3\n");
	printf("flow = %i\n", flow);
	free_struct(&dub);
	return (flow);
}
