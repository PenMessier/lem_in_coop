/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:53:03 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 15:44:07 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int						ft_sol_len(t_solution *sol)
{
	int					best;
	int					i;

	i = 0;
	best = 0;
	while (i < sol->n_paths)
	{
		if (best < sol->paths[i].length)
			best = sol->paths[i].length;
		i++;
	}
	return (best);
}

void					ft_way_fill(t_way *str, t_path *tar, t_room *start)
{
	int				i;
	t_room			*room;

	i = 0;
	room = tar->origin;
	while (i < tar->length)
	{
		i++;
		str--;
	}
	str->roomno = start->i;
	str->room = start->name;
	str++;
	i = 0;
	while (room != NULL)
	{
		str->room = room->name;
		str->roomno = room->i;
		str++;
		room = room->best_succ;
		i++;
	}
}

void					ft_print_sol(int a, int b, t_solution *sol, t_map *map)
{
	t_way				cool[a * (b + 2)];
	int					i;

	ft_full(cool, b + 2, a);
	i = 0;
	while (i < a)
	{
		ft_way_fill(cool + ((b + 2) * (i + 1)) - 1,
			&(sol->paths)[i], map->start);
		i++;
	}
	ft_rotate(b + 2, a, cool, map);
	return ;
}

void					ft_best(t_map *map)
{
	int			max_paths;
	int			path_count;
	t_solution	*best_sol;

	path_count = 0;
	best_sol = NULL;
	max_paths = ft_max_link(map);
	while (path_count < max_paths && find_more_paths(map))
	{
		++path_count;
		solution_improve(&(best_sol), map, map->start, path_count);
	}
	if (best_sol)
	{
		ft_print_sol(best_sol->n_paths, ft_sol_len(best_sol), best_sol, map);
		free(best_sol->paths);
		free(best_sol->ants_per_path);
		free(best_sol);
	}
}
