/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:50:23 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/11 12:30:47 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);
int		base_check(char *base);
int		find_nbr(char *base, char tgt);
char	*conv_base_from(char *nbr, char *base_from);

void	ft_rev_char_tab(char *tab, int size)
{
	int		i;
	char	tmp[size];

	i = 0;
	while (i < size)
	{
		tmp[i] = *(tab + i);
		i++;
	}
	while (i-- > 0)
	{
		*tab = tmp[i];
		tab++;
	}
}

char	*long_to_base(int num, char *base_to)
{
	char	*dest;
	int		i;
	int		tmp;
	
	dest = (char *)malloc(sizeof(char) * 20);
	if (!dest)
		return (0);
	*dest = 0;
	i = 0;
	tmp = num;
	if (num < 0)
		tmp *= -1;
	while (tmp >= 0)
	{
		dest[i++] = base_to[tmp % ft_strlen(base_to)];
		tmp /= ft_strlen(base_to);
		if (tmp == 0)
			break ;
	}
	if (num < 0)
		dest[i++] = '-';
	dest[i] = '\0';
	ft_rev_char_tab(dest, i);
	return (dest);
}

long	base_to_long(char *nbr, char *base_from)
{
	long	num;
	int		nbase;
	int		i;

	num = 0;
	nbase = ft_strlen(base_from);
	i = 0;
	while (nbr[i])
		num = num * nbase + find_nbr(base_from, nbr[i++]);
	return (num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*valid_nbr;
	long	tmp;
	int		minus;
	char	*dest;

	minus = 1;
	if (base_check(base_from) || base_check(base_to))
		return (0);
	while (*nbr == ' ' || (9 <= *nbr && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			minus *= -1;
		nbr++;
	}
	valid_nbr = conv_base_from(nbr, base_from);
	tmp = base_to_long(valid_nbr, base_from);
	free(valid_nbr);
	tmp *= minus;
	dest = long_to_base(tmp, base_to);
	return (dest);
}

int	main()
{
	char nbr[] = "12345";
	char base_from[] = "12345";
	char base_to[] = "12345";
	printf("%s\n", ft_convert_base(nbr, base_from, base_to));
	return (0);
}