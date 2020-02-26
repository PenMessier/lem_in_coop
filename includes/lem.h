/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:58:30 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:15:14 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "../libft/libft.h"
# include <errno.h>

#define  DEBUG 0

typedef struct		s_room
{
	int				i;
	char			*name;
	int				x;
	int				y;
	int				stat; //used - 1, unused - 0, start - 2, end - 3
	int				ant;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	t_room			*start;
	t_room			*end;
	struct s_link	*next;
}					t_link;

typedef struct		s_meta
{
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_link			*links;
	int				ant_count;
	int				n;
	int				*c;
	int     		*f;
	int     		s;
	int     		t;
	int     		*d;
	int     		*ptr;
	int     		*q;
	int				maxn;
}					t_meta;

void			*ft_memset(void *b, int c, size_t len);
void			ft_pr_f(t_meta *all);
void			input(t_meta *all, int maxn);
int				imin(int a, int b);
int				bfs(t_meta *all);
int				dfs (int v, int flow, t_meta *all);
int				dinic(t_meta *all);
void			ft_dub(t_meta *all, t_meta *dub);
void    		ft_undub(t_meta *all, t_meta *dub);
void			tf_nodewae(t_meta *all, int *wae, int nom);

/*
** Parse input
*/

void				ft_parse(char *input, t_meta *map, int *nl);

/*
** Validation functions
*/

void				valid_ants(char *input, t_meta *map);
void				valid_room(char *input, t_meta *map, int *nl);
void				valid_link(char *input, t_meta *map);
//int					valid_map(t_meta map);

/*
** Error management functions
*/

void				put_error(t_meta *map, int r);

/*
** Struct room utility functions
*/

t_room				*create_new_room(int x, int y, char *name, int li);
int					add_room(t_room *new, t_meta *map, int *nl);
t_room				*find_room(t_room *rooms, char *name);

int					add_link(t_link **links, t_room *start, t_room *end);

void				free_struct(t_meta *map);
void				print_input(t_meta map);

#endif
