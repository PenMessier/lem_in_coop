/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_lem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:11 by frenna            #+#    #+#             */
/*   Updated: 2020/02/29 13:24:59 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		find_paths(t_meta *all)
{
	int i;
	int *wae;
	int j;

	i = 0;
	input(all);
	j = dinic(all);
	j = ft_abs(j);
	//ft_pr_f(all);
	if (!(wae = (int *)malloc(sizeof(int) * all->room_count * j)))
		put_error(all, 1);
	while (i < all->room_count * j)
		wae[i++] = -1;
	i = 0;
/*	while (i < all->room_count * j)
	{
		if (i == all->room_count)
			printf("\n");
      printf("%2i", wae[i]);
		i++;
	}
	printf("\n");*/
	tf_nodewae(all, wae, j);
	i = 0;
	while (i < all->room_count * j)
	{
		if (i == all->room_count)
			printf("\n");
		printf("%2i", wae[i]);
		i++;
	}
	printf("\n");
}
