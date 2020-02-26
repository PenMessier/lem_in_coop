/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:46 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:04:15 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int     dinic(t_meta *all)
{
	int	flow;
	int	pushed;
	t_meta	*dub;
	int i;
	
	flow = 0;
	i = 0;
	dub = NULL;
	while (dub == NULL && i < 5)
        {
                dub = (t_meta*)malloc(sizeof(t_meta));
                i++;
        }
	if(dub == NULL )
                exit (0);
/*	while(bfs(all))
	{
		memset(all->ptr, 0, all->n * sizeof all->ptr[0]);
		while ((pushed = dfs (all->s, 1234567890, all)))
			flow += pushed;
	}*/
	ft_dub(all, dub);
	while(bfs(dub))
        {
                memset(dub->ptr, 0, dub->n * sizeof dub->ptr[0]);
                while ((pushed = dfs (dub->s, 1234567890, dub)))
                        flow += pushed;
        }
	ft_undub(all, dub);
	printf("DUB3\n");
        ft_pr_f(dub);
        printf("DUB3\n");
	printf("flow = %i\n", flow);
	return flow;
}
