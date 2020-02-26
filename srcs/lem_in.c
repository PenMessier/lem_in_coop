/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:19:18 by Elena             #+#    #+#             */
/*   Updated: 2020/02/26 16:16:47 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	init_meta(t_meta *map)
{
	map->rooms = NULL;
	map->links = NULL;
}

int			main(int ac, char **av)
{
	char	*input;
	t_meta	lemin;
	int		nl;

	nl = 2;
	init_meta(&lemin);
	if (ac == 1)
	{
		while (get_next_line(0, &input))
		{
			ft_parse(input, &lemin, &nl);
			free(input ? input : NULL);
			if (nl == -1)
				put_error(&lemin, 1);
		}
		//print_input(lemin);
		free_struct(&lemin);
	}
	av = 0;
	return (0);
}
