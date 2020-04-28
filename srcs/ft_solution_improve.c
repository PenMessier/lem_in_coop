/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_improve.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:03:09 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 15:45:59 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void		solution_save(t_solution const *solution)
{
	int			i;
	t_room		*room;

	i = 0;
	while (i < solution->n_paths)
	{
		room = solution->paths[i].origin;
		while (room->succ != NULL)
		{
			room->best_succ = room->succ;
			room = room->succ;
		}
		++i;
	}
}

void			solution_improve(t_solution **best_solution,
						t_map *map, t_room *start, int path_count)
{
	t_solution	*solution;

	solution = solution_build(map, start, path_count);
	if (*best_solution == NULL
			|| solution->n_turns < (*best_solution)->n_turns)
	{
		solution_save(solution);
		if (*best_solution != NULL)
			solution_destroy(*best_solution);
		*best_solution = solution;
	}
	else
		solution_destroy(solution);
}
