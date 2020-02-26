/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:45:07 by frenna            #+#    #+#             */
/*   Updated: 2020/02/09 09:40:17 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new item and pushes it to the end of the list pointed by **s
** if the list is not NULL. Otherwise sets the head of the list to be
** a new item.
*/

void				ft_init(t_node **s, char *content, int fd, size_t c_size)
{
	t_node			*curr;
	t_node			*new;

	if (!c_size || !(new = (t_node *)malloc(sizeof(*new))))
		return ;
	new->content = ft_strnew(c_size);
	if (!new->content)
	{
		free(new);
		return ;
	}
	ft_memcpy(new->content, content, c_size);
	new->fd = fd;
	new->content_size = c_size;
	new->next = NULL;
	if (*s == NULL)
	{
		*s = new;
		return ;
	}
	curr = *s;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return ;
}

/*
** Iterates over the list until the item
** with given fd is found. Copies the content
** from the item to the line. Frees memory allocated
** for the item content. If the item is a head of the
** list sets head's pointer to the next item and frees
** memory allocated to the item.
** Replaces '\n' in the line with '\0'.
*/

void				ft_line(t_node **s, char **line, int fd)
{
	t_node			*curr;
	t_node			*tmp;

	curr = *s;
	while (curr)
	{
		if (curr->fd == fd)
		{
			*line = ft_strcat(*line, curr->content);
			tmp = curr;
			ft_strdel(&(tmp->content));
			if (tmp == *s)
			{
				*s = (*s)->next;
				free(tmp);
			}
		}
		curr = curr->next;
		if (ft_strrchr(*line, '\n'))
			break ;
	}
	ft_strrchr(*line, '\n') ? *ft_strrchr(*line, '\n') = '\0' : 0;
}

/*
** Iterates over the list to add content_sizes of every
** node with given fd untill the node which containes '\n'
** or the list's end. Allocates memory for the line.
** Iterates over the list to free all empty nodes.
*/

void				ft_size(t_node **s, int fd, char **line, size_t f)
{
	t_node			*tmp;
	t_node			*curr;

	tmp = *s;
	f = 0;
	while (tmp)
	{
		(tmp->fd == fd) ? f += tmp->content_size : 0;
		if (ft_strrchr(tmp->content, '\n'))
				break ;
		tmp = tmp->next;
	}
	(*line = ft_strnew(f)) ? ft_line(s,line, fd) : 0;
	curr = *s;
	while (curr && curr->next != NULL)
	{
		if (!curr->next->content)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		else
			curr = curr->next;
	}
}

/*
** Finds the end of the line ('\n') if it exists in the buffer,
** upgrades *f to 1. Then creates a new list element and puts
** buffer content untill '\n' in it. Since the buffer contains
** characters after '\n' creates a new element and
** puts the rest of buffer content there.
*/

size_t				ft_r(int fd, ssize_t rd, t_node **s, char *buff)
{
	char			*tmp;
	char			*curr;
	int				i;

	i = 1;
	tmp = buff;
	if (ft_strrchr(buff, '\n'))
	{
		while (*tmp)
		{
			if (*tmp == '\n')
			{
				ft_init(s, curr, fd, i);
				curr = tmp + 1;
				i = 0;
			}
			i++;
			tmp++;
		}
		(*tmp - *curr != 0) ? ft_init(s, curr, fd, i) : 0;
		return (1);
	}
	else
		ft_init(s, buff, fd, rd);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[1];
	char			*buff;
	static	t_node	*s;
	size_t			f;
	ssize_t			rd;

	if (fd < 0 || !line || read(fd, (void *)buf, 0) < 0 || !BUFF_SIZE)
		return (-1);
	f = 0;
	while (f == 0 && (buff = ft_strnew(BUFF_SIZE))
	&& (rd = read(fd, (void *)buff, BUFF_SIZE)))
	{
		f = ft_r(fd, rd, &s, buff);
		ft_strdel(&buff);
	}
	buff ? ft_strdel(&buff) : 0;
	ft_size(&s, fd, line, f);
	return (*line ? 1 : 0);
}
