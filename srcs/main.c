/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:54:51 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 22:09:04 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			main(int ac, char **av)
{
	t_map	lemin;

	if (ac == 1)
	{
		if (fill_map(&lemin))
			find_paths(&lemin);
		// ft_print_input(lemin);
		free_struct(&lemin);
	}
	av = 0;
	return (0);
}
