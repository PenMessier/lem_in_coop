/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:54:51 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 13:02:20 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			main(int ac, char **av)
{
	t_map	lemin;

	if (ac == 1)
	{
		fill_map(&lemin);
		// ft_print_input(lemin);
		find_paths(&lemin);
		free_struct(&lemin);
	}
	av = 0;
	return (0);
}
