/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:46 by frenna            #+#    #+#             */
/*   Updated: 2020/03/03 15:04:00 by Elena            ###   ########.fr       */
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
		ft_memset((&dub)->ptr, 0, (&dub)->room_count * sizeof((&dub)->ptr[0]));
		while ((pushed = dfs((&dub)->s, 1234567890, &dub)))
			flow += pushed;
	}
	//printf("bfs %d\n", test);
	ft_undub(all, &dub);
	//printf("DUB3\n");
	//ft_pr_f(&dub);
	// ft_pr_f(all);
	//printf("DUB3\n");
	printf("flow = %i\n", flow);
	free_struct(&dub);
	return (flow);
}
