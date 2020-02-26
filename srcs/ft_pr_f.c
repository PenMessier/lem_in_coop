/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:59:08 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:04:37 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	ft_pr_f(t_meta *all)
{
	int i;
	int j;
	int nom;

	printf("n = %i\n", all->n);
	printf("s = %i\n", all->s);
	printf("t = %i\n", all->t);
	printf("maxn = %i\n", all->maxn);
	printf("f\n");
        printf("[  ]");
        for(i = 0; i < all->maxn; i++){
                printf("[%2i]", i);
        }
        printf("\n");
        for(i = 0; i < all->maxn; i++){
                printf("[%2i]", i);
                for (j = 0; j < all->maxn; j++){
                        nom = i * all->maxn + j;
                        if (all->f[nom] == 1)
                                printf("[ +]");
			else if (all->f[nom] == -1)
                                printf("[ -]");
			else if (i == j)
                                printf("[ *]");
                        else if (all->f[nom] == 0)
                                printf("[  ]");
                        else
                                printf("[%2i]", all->f[nom]);
                }
                printf("\n");
        }
	printf("c\n");
        printf("[  ]");
        for(i = 0; i < all->maxn; i++){
                printf("[%2i]", i);
        }
        printf("\n");
        for(i = 0; i < all->maxn; i++){
                printf("[%2i]", i);
                for (j = 0; j < all->maxn; j++){
                        nom = i * all->maxn + j;
                        if (all->c[nom] == 1 || all->c[nom] == -1)
                                printf("[ *]");
                        else if (all->c[nom] == 0)
                                printf("[  ]");
                        else
                                printf("[%2i]", all->c[nom]);
                }
                printf("\n");
        }
}
