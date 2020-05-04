/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:54:32 by gerenfor          #+#    #+#             */
/*   Updated: 2020/05/03 21:27:45 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_file(int fd, char **sum)
{
	char			buf[BUFF_SIZE + 1];
	int				n;
	char			*new;

	n = 1;
	if (*sum == NULL)
	{
		ft_bzero(buf, (BUFF_SIZE + 1));
		if ((n = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		if (n == 0)
			return (0);
		*sum = ft_strdup(buf);
	}
	while (!ft_strchr(*sum, '\n') && n != 0)
	{
		ft_bzero(buf, (BUFF_SIZE + 1));
		if ((n = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		new = ft_strjoin(*sum, buf);
		ft_strdel(sum);
		*sum = new;
		new = NULL;
	}
	return (1);
}

static void		cut_it(char **sum, char **line, t_kor **dop, int fd)
{
	int				flag;
	t_kor			*tmp;
	t_kor			*del;

	flag = (ft_strchr(*sum, '\n') - *sum);
	*line = ft_strsub(*sum, 0, flag);
	if ((ft_strlen(*sum) - (flag + 1)) > 0)
	{
		tmp = *dop;
		del = (t_kor*)malloc(sizeof(t_kor));
		del->fd = fd;
		del->line = ft_strsub(*sum, (flag + 1), ft_strlen(*sum) - flag);
		del->next = NULL;
		if (*dop == NULL)
			*dop = del;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = del;
		}
	}
	free(*sum);
	*sum = NULL;
}

static t_kor	*delit_kor(t_kor **dop, int fd)
{
	t_kor			*del;
	t_kor			*tmp;

	del = NULL;
	if ((*dop)->fd == fd)
	{
		del = *dop;
		*dop = (*dop)->next;
	}
	else if ((*dop)->next != NULL)
	{
		tmp = *dop;
		while (tmp->next->fd != fd && tmp->next->next != NULL)
			tmp = tmp->next;
		if (tmp->next->fd == fd)
		{
			del = tmp->next;
			tmp->next = tmp->next->next;
		}
	}
	return (del);
}

static void		read_kor(char **sum, t_kor **del)
{
	*sum = ft_strdup((*del)->line);
	ft_strdel(&((*del)->line));
	(*del)->fd = 0;
	free(*del);
	*del = NULL;
}

int				get_next_line(const int fd, char **line)
{
	static t_kor	*dop = NULL;
	char			*sum;
	t_kor			*del;
	int				flag;

	if (fd < 0)
		return (-1);
	flag = 1;
	sum = NULL;
	if (dop != NULL)
	{
		del = delit_kor(&dop, fd);
		if (del != NULL)
			read_kor(&sum, &del);
	}
	flag = read_file(fd, &sum);
	if (flag <= 0)
		return (flag);
	if (ft_strchr(sum, '\n'))
		cut_it(&sum, line, &dop, fd);
	else
		*line = sum;
	return (1);
}
