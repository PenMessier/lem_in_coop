/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_write_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 09:18:50 by Elena             #+#    #+#             */
/*   Updated: 2020/03/23 09:24:16 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		write_ants(int fd, char *input, int *f)
{
	*f = 3;
	write (fd, "{\n", 2);
	write (fd, "\t\"ants\": ", 9);
	write (fd, input, ft_strlen(input));
	write (fd, ",\n", 2);
	write (fd, "\t\"rooms\": {\n", 12);
}

void		write_room(int fd, char *input)
{
	int		x;
	int		y;
	char	*tmp;
	int		len;

	valid_line_room(input, &x, &y, &len);
	write (fd, "\t\t\"", 3);
	write (fd, input, len);
	write (fd, "\": { \"x\": ", 10);
	tmp = ft_itoa(x);
	write (fd, tmp, ft_strlen(tmp));
	write (fd, ", \"y\": ", 7);
	free(tmp ? tmp : NULL);
	tmp = ft_itoa(y);
	write (fd, tmp, ft_strlen(tmp));
	free(tmp ? tmp : NULL);
	write (fd, " }", 2);
}

void		write_link(int fd, char *input)
{
	int		l;

	l = 0;
	while (input[l] != '-')
		l++;
	write (fd, "\t\t[\"", 4);
	write (fd, input, l);
	write (fd, "\", \"", 4);
	l++;
	write (fd, &input[l], ft_strlen(input) - l);
	write (fd, "\"]", 2);
}

void		write_step(int fd, char *input)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	write (fd, "\t\t{ ", 4);
	while (input[l])
	{
		if (i > 0)
			write (fd, ", ", 2);
		while (input[l] != '-')
			l++;
		write (fd, "\"", 1);
		write (fd, &input[i], l - i);
		write (fd, "\": \"", 4);
		i = ++l;
		while (input[i] && input[i] != ' ')
			i++;
		write (fd, &input[l], i - l);
		write (fd, "\"", 1);
		l = ++i;
	}
	write (fd, " }", 2);
}
