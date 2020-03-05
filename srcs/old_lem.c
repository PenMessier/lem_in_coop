/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_lem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:11 by frenna            #+#    #+#             */
/*   Updated: 2020/03/03 15:03:42 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	test(t_meta *one)
{
	int				i;
	int				j;
	int				k;

	k = 0;
	for (i = 0; i < one->room_count; i++)
	{
		for (j = 0; j < one->room_count; j++)
		{
			if (i != j)
				if (one->c[i * one->room_count + j] != one->c[j * one->room_count + i])
				{
					printf("c[%i][%i] != c[%i][%i]\n", i, j, j, i);
					k = 1;
				}
		}
	}
	if (k == 0)
	printf("all right\n");
} 

void		find_paths(t_meta *all)
{
	int i;
	int *wae;
	int j;

	i = 0;
	input(all);
	test(all);
	j = dinic(all);
	//ft_pr_f(all);
	j = ft_abs(j);
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
