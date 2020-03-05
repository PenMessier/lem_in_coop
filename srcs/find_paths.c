/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_lem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:11 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 13:45:03 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

/*static void	test(t_map *one)
{
	int				i;
	int				flow;
	int				k;

	k = 0;
	for (i = 0; i < one->room_count; i++)
	{
		for (flow = 0; flow < one->room_count; flow++)
		{
			if (i != flow)
				if (one->c[i * one->room_count + flow] != one->c[flow * one->room_count + i])
				{
					printf("c[%i][%i] != c[%i][%i]\n", i, flow, flow, i);
					k = 1;
				}
		}
	}
	if (k == 0)
	printf("all right\n");
} 
*/

void		init_meta(t_meta *meta)
{
	meta->s = 0;
	meta->t = 0;
	meta->c = 0;
	meta->f = 0;
	meta->d = 0;
	meta->ptr = 0;
	meta->q = 0;
}

void		find_paths(t_map *map)
{
	int 	i;
	int 	*wae;
	int 	flow;

	i = 0;
	if (!(map->all = (t_meta *)malloc(sizeof(t_meta))))
		put_error(map, 1);
	init_meta(map->all);
	create_link_matrix(map);
	if (!(flow = dinic(map->all)))
		put_error(map, 10);
	if (!(wae = (int *)malloc(sizeof(int) * map->room_count * flow)))
		put_error(map, 1);
	ft_memset(wae, -1, map->room_count * flow * sizeof(int));
	tf_nodewae(map->all, wae, flow);
	// ft_pr_f(map->all);
	printf("flow = %i\n", flow);
	while (i < map->room_count * flow)
	{
		if (!(i % map->room_count) && i)
			printf("\n");
		if (wae[i] != -1)
			printf("%3i", wae[i]);
		i++;
	}
	printf("\n");
}
