/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:54:51 by frenna            #+#    #+#             */
/*   Updated: 2020/04/29 09:58:47 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			main(int ac, char **av)
{
	t_map	lemin;
	int		fd;

	fd = 0;
	if (ac > 2)
	{
		perror("Invalid number of arguments");
		exit(2);
	}
	else if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			perror("Opening file failed");
			exit(2);
		}
	}
	fill_map(&lemin, fd);
	find_paths(&lemin);
	free_struct(&lemin);
	// system("leaks -q lem-in >&2");
	return (0);
}
