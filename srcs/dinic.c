/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:46 by frenna            #+#    #+#             */
/*   Updated: 2020/02/29 14:03:44 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int     	dinic(t_meta *all)
{
	int		flow;
	int		pushed;
	t_meta	dub;
	int		test;
	
	flow = 0;
	init_meta(&dub);
	ft_dub(all, &dub);
	while((test = bfs(&dub)))
	{
		printf("bfs %d\n", test);
		ft_memset((&dub)->ptr, 0, (&dub)->room_count * sizeof((&dub)->ptr[0]));
		while ((pushed = dfs((&dub)->s, 1234567890, &dub)))
		{
			printf("pushed %d\n", pushed);
			flow += pushed;
		}
	}
	printf("bfs %d\n", test);
	ft_undub(all, &dub);
	printf("DUB3\n");
	//ft_pr_f(&dub);
	ft_pr_f(all);
	printf("DUB3\n");
	printf("flow = %i\n", flow);
	free_struct(&dub);
	return (flow);
}
