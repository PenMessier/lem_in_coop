/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:19:36 by syeresko          #+#    #+#             */
/*   Updated: 2020/04/29 14:05:20 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

# define ALLOCERR -5

# define LINK_POSITIVE	1
# define LINK_ZERO		0
# define LINK_NEGATIVE	(-1)

/*
**	generic singly-linked list
**	`list_push` prepends a new item containing the specified data.
**	`list_pop` deletes the first item and returns its data.
**	The trick to insert or remove an item in the middle or end of a list,
**	say right after an item pointed to by `t_list *item`, is to pass
**	`&item->next` as the `head` parameter to these functions.
*/

typedef struct		s_list
{
	void				*data;
	struct s_list		*next;
}					t_list;

/*
**	i - room index;
**	name - room name
**	x, y - coordinates
**	links - list or neighbours
**	level - distance from start room
**	parent - find_shortest_path
**	pred, succ - rooms in pass
**	next - in total list of rooms
**	`room_new` allocates and initializes a room.
**	`room_find` returns a room by its name or NULL if it is not in the list.
*/

typedef struct		s_room
{
	int					i;
	char				*name;
	int					x;
	int					y;
	int					stat;
	int					ant;
	int					level;
	t_list				*links;
	struct s_room		*parent;
	struct s_room		*pred;
	struct s_room		*succ;
	struct s_room		*best_succ;
	struct s_room		*next;
}					t_room;

/*
**	set of rooms
**
**	`set_new` returns a new empty set.
**	`set_push` includes a room in the set if it is not already there.
**	`set_pop_min` excludes from the set and returns a room with the smallest
**		distance; if the set is empty, does nothing and returns NULL.
**	`set_destroy` empties and deletes the set.
*/

typedef struct		s_set
{
	t_list				*elements;
}					t_set;

typedef struct		s_line
{
	t_room				*dst;
	int					weight;
}					t_line;

typedef struct		s_path
{
	t_room				*origin;
	int					length;
}					t_path;

typedef struct		s_solution
{
	t_path				*paths;
	int					n_paths;
	int					*ants_per_path;
	unsigned long int	n_turns;
}					t_solution;

typedef struct		s_link
{
	t_room				*start;
	t_room				*end;
	struct s_link		*next;
}					t_link;

typedef struct		s_way
{
	int					roomno;
	int					ant;
	char				*room;
}					t_way;

typedef struct		s_map
{
	t_room				*rooms;
	t_room				*start;
	t_room				*end;
	t_link				*links;
	t_list				*list;
	int					ant_count;
	int					room_count;
}					t_map;

/*
**	weighted directed link between rooms
**
**	`link_push` creates a new link to `dst` of specified weight
**		and prepends it to the list of links from `src`.
**	`link_pop` removes the room's first link and returns its destination
**		(`src` must have at least one link).
**	`link_delete` removes the link to `dst` from `src` (the link must
**		actually exist).
**	`link_find` returns the link between the given rooms or NULL if they
**		are not linked.
*/

void				list_push(t_list **head, void *data, t_map *map);
void				*list_pop(t_list **head);
void				line_push(t_room *src, t_room *dst, int weight, t_map *map);
t_room				*line_pop(t_room *src);
void				line_delete(t_room *src, t_room *dst);
t_line				*line_find(t_room const *src, t_room const *dst);

t_set				*set_new(t_map *map);
void				set_push(t_set *set, t_room *room, t_map *map);
t_room				*set_pop_min(t_set *set);
void				set_destroy(t_set *set);

#endif
