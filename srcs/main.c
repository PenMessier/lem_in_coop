/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:54:51 by frenna            #+#    #+#             */
/*   Updated: 2020/03/23 10:31:08 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			main(int ac, char **av)
{
	t_map	lemin;
	int		fd;

	fd = 0;
	if (ac > 2)
		put_error(&lemin, 1);
	else if (ac == 2)
		if (!(fd = open(av[1], O_RDONLY)))
			put_error(&lemin, 1);
	if (!fill_map(&lemin, fd))
		put_error(&lemin, 1);
	find_paths(&lemin);
	free_struct(&lemin);
	return (0);
}
