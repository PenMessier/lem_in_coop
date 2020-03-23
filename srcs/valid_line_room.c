/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 08:31:40 by Elena             #+#    #+#             */
/*   Updated: 2020/03/23 10:36:39 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int		find_coord(char *s, int *i)
{
	int	l;

	l = 0;
	while (s[*i] && s[*i] != 32 && s[*i] > 47 && s[*i] < 58)
		*i -= 1;
	if (*i == l)
		return (0);
	if (s[*i] == 45 && s[*i - 1] == 32)
		i -= 1;
	else if (s[*i] != 32)
		return (0);
	return (1);
}

int		valid_line_room(char *s, int *x, int *y, int *li)
{
	int	i;

	i = 0;
	if (s[0] == 'L' || s[0] == '#')
		return (0);
	while (s[i])
		i++;
	i--;
	if (!find_coord(s, &i))
		return (0);
	*y = ft_atoi(&s[i]);
	i--;
	if (!find_coord(s, &i))
		return (0);
	*x = ft_atoi(&s[i]);
	*li = i--;
	return (*li >= 0 ? 1 : 0);
}
