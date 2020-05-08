/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:54:51 by frenna            #+#    #+#             */
/*   Updated: 2020/05/08 11:57:22 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			main(int ac, char **av)
{
	t_map	lemin;
	int		fd;

	fd = 0;
	if (ac > 2)
		put_error(NULL, -14);
	else if (ac == 2)
		if ((fd = open(av[1], O_RDONLY)) < 0)
			put_error(NULL, -15);
	fill_map(&lemin, fd);
	find_paths(&lemin);
	free_struct(&lemin);
	return (0);
}
