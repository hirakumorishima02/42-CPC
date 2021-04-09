/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:50:26 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/11 12:29:41 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	cnt;

	if (!str)
		return (-1);
	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int		base_check(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				return (1);
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '%'
				|| base[i] == '/' || base[i] == '*' || base[i] == '='
				|| base[i] == ',' || base[i] == '.'
				|| base[i] < 33 || base[i] > 126)
			return (1);
		else
			i++;
	}
	return (0);
}

int		find_nbr(char *base, char tgt)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i++] == tgt)
			return (i);
	}
	return (-1);
}

char	*conv_base_from(char *nbr, char *base_from)
{
	int		i;
	char	*valid_nbr;

	i = 0;
	valid_nbr = (char *)malloc(sizeof(char) * 20);
	if (!valid_nbr)
		return (0);
	*valid_nbr = 0;
	while (find_nbr(base_from, nbr[i]) >= 0)
	{
		valid_nbr[i] = nbr[i];
		i++;
	}
	valid_nbr[i] = '\0';
	return (valid_nbr);
}