/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:11 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 15:45:56 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	find_paths(t_map *map)
{
	int	i;
	int	*wae;
	int flow;
	int	max;

	i = 0;
	if (!(map->all = (t_meta *)malloc(sizeof(t_meta))))
		put_error(map, 1);
	ft_init_meta(map->all);
	if (!create_link_matrix(map))
		put_error(map, 1);
	flow = dinic(map->all);
	if (flow < 0)
		put_error(map, 1);
	if (!flow)
		put_error(map, 10);
	if (!(wae = (int *)malloc(sizeof(int) * map->room_count * flow)))
		put_error(map, 1);
	ft_memset(wae, -1, map->room_count * flow * sizeof(int));
	max = ft_nodewae(map->all, wae, flow);
	/*printf("max %d\n", max);
	printf("flow %d\n", flow);
	while (i < map->room_count * flow)
	{
		if (i == map->room_count)
			printf("\n");
		if (wae[i] != -1)
			printf("%d ", wae[i]);
		i++;
	}*/
	ft_queen(max, flow, wae, map);
	free(wae);
}
