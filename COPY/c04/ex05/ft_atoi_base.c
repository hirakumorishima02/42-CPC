/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 08:23:37 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/12 06:39:19 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (*base++)
		i++;
	return (i);
}

int		get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		change_base_num(char *str, char *base)
{
	int		num;
	int		num_sign;
	
	num = 0;
	num_sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (get_index(*str, base) == -1)
	{
		if (*str == '-')
			num_sign *= -1;
		else if (*str != '+')
			return (0);
		str++;
	}
	while (get_index(*str, base) > -1)
		num = ft_strlen(base) * num + (get_index(*str++, base));
	return (num_sign == 1 ? num : -num);
}

int		ft_charstr_cmp(char c, char *base)
{
	int	cnt;
	
	cnt = 0;
	while(*base)
	{
		if(*base == c)
			cnt++;
		base++;
	}
	return (cnt);
}

int		ft_atoi_base(char *str, char *base)
{
	char *tmp;

	if (ft_strlen(base) <= 1)
		return (0);
	if (ft_charstr_cmp('+', base) > 0 || ft_charstr_cmp('-', base) > 0
			||  ft_charstr_cmp(' ', base) > 0 || ft_charstr_cmp('\t', base) > 0
			|| ft_charstr_cmp('\n', base) > 0 || ft_charstr_cmp('\v', base) > 0
			|| ft_charstr_cmp('\f', base) > 0 || ft_charstr_cmp('\r', base) > 0)
		return (0);
	tmp = base;
	while (*tmp)
	{
		if (ft_charstr_cmp(*tmp, base) > 1)
			return (0);
		tmp++;
	}
	return (change_base_num(str, base));
}

#include <stdio.h>
int main()
{
	char str[] = "---+194384";
	char base[] = "0123456789ABCDEF";
	int n = ft_atoi_base(str, base);
	printf("%d\n", n);
}