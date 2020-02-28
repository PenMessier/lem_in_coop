/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:46 by frenna            #+#    #+#             */
/*   Updated: 2020/02/27 20:05:11 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int     dinic(t_meta *all)
{
	int	flow;
	int	pushed;
	t_meta	dub;
	
	flow = 0;
	ft_dub(all, &dub);
	while(bfs(&dub))
	{
		ft_memset((&dub)->ptr, 0, (&dub)->n * sizeof(int));
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
