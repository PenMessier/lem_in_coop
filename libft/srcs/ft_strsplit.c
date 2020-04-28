/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 08:53:28 by frenna            #+#    #+#             */
/*   Updated: 2019/05/14 10:23:51 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_create_string(const char *str, char c, int *i)
{
	char	*sub;
	int		k;

	if (!(sub = (char *)malloc(sizeof(sub) * ft_strlen(str))))
	{
		free(sub);
		return (0);
	}
	k = 0;
	while (str[*i] != c && str[*i])
	{
		sub[k] = str[*i];
		k++;
		*i += 1;
	}
	sub[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (sub);
}

static	void	ft_freestr(char **str)
{
	if (str)
	{
		while (*str)
		{
			free(str);
			str++;
		}
	}
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	char	**s;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	if (!(s = (char **)malloc(sizeof(s) * (ft_count_words(str, c) + 1))))
	{
		free(s);
		return (0);
	}
	while (str[i] == c && str[i])
		i++;
	while (j < ft_count_words(str, c) && str[i])
	{
		s[j] = ft_create_string(str, c, &i);
		if (!s[j])
			ft_freestr(s);
		j++;
	}
	s[j] = 0;
	return (s);
}
