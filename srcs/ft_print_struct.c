/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:11 by frenna            #+#    #+#             */
/*   Updated: 2020/04/27 14:19:25 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	ft_print_room_links(t_list *link)
{
	t_line *tmp;

	while (link != NULL)
	{
		tmp = (t_line*)link->data;
		printf("[%s](%i) ", tmp->dst->name, tmp->weight);
		link = link->next;
	}
	printf("\n");
}

void	ft_print_list_links(t_list *link)
{
	t_room *tmp;

	while (link != NULL)
	{
		tmp = (t_room*)link->data;
		printf("[%s] ", tmp->name);
		link = link->next;
	}
	printf("\n");
}

void	ft_print_rooms(t_room *room)
{
	while (room != NULL)
	{
		printf("Room %i %s(%i,%i)\n", room->i, room->name, room->x, room->y);
		printf("stat = %i, ant = %i, level = %i\n", room->stat, room->ant, room->level);
		ft_print_room_links(room->links);
		if (room->parent != NULL)
			printf("parent %s;", room->parent->name);
		else
			printf("parent NULL;");
		if (room->pred != NULL)
			printf("pred %s;",  room->pred->name);
		else
			printf("pred NULL;");
		if (room->succ != NULL)
			printf("succ %s;", room->succ->name);
		else
			printf("succ NULL;");
		if (room->best_succ != NULL)
			printf("best_succ %s\n", room->best_succ->name);
		else
			printf("best_succ NULL;\n");
		printf("\n");
		room = room->next;
	}
}

void	ft_print_links(t_link *link)
{
	int i;

	i = 0;
	while (link != NULL)
	{
		printf("Link %i) %s - %s\n", i, link->start->name, link->end->name);
		i++;
		link = link->next;
	}
}

void	ft_print(t_map *map)
{
	printf("Print map start\n");
	ft_print_rooms(map->rooms);
	printf("start - %s; end - %s\n", map->start->name, map->end->name);
	ft_print_links(map->links);
	printf("ant_count = %i; room_count = %i\n", map->ant_count, map->room_count);
	ft_print_list_links(map->list);
	printf("Print map end\n");
}
