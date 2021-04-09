/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:23:46 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/06 06:51:54 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strcpy(char *dest, char *src)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (src[i] != '\0')
		dest[i++] = src[c++];
	dest[i] = '\0';
	return (dest);
}

char			*ft_strdup(char *src)
{
	char *dest;

	if (src == NULL)
		return (0);
	dest = (char*)malloc(ft_strlen(src) + 1);
	if (dest)
		ft_strcpy(dest, src);
	return (dest);
}

struct			s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*st;

	st = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (st == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		st[i].size = ft_strlen(av[i]);
		st[i].str = av[i];
		st[i].copy = ft_strdup(av[i]);
		i++;
	}
	st[i].size = 0;
	st[i].str = 0;
	st[i].copy = 0;
	return (st);
}
