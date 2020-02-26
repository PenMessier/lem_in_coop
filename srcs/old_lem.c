/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_lem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:11 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:19:54 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int main()
{
	t_meta *all;
	int i;
	int *wae;
	int j;

	all = NULL;
	i = 0;
	while (all == NULL && i < 5)
	{
		all = (t_meta*)malloc(sizeof(t_meta));
		i++;
	}
	if(all == NULL )
		exit (0);
	input(all, 6);
	j = dinic(all);
	ft_pr_f(all);
	wae = NULL;
        i = 0;
        while (wae == NULL && i < 5)
        {
                wae = (int*)malloc(sizeof(int*) * all->maxn * j);
                i++;
        }
	i = 0;
	while (i < all->maxn * j)
	{
		wae[i] = -1;
		i++;
	}
	i = 0;
	while (i < all->maxn * j)
    {
		if (i == all->maxn)
			printf("\n");
                printf("%2i", wae[i]);
		i++;
    }
	printf("\n");
	tf_nodewae(all, wae, j);
	i = 0;
	while (i < all->maxn * j)
	{
		if (i == all->maxn)
				printf("\n");
		printf("%2i", wae[i]);
		i++;
	}
	printf("\n");
	return 0;
}
