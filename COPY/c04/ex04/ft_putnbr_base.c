/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:26:47 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/06 18:26:27 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}

void		base_check(char *base, int *error)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		*error = 1;
	while (base[i] && *error == 0)
	{
		j = i;
		if (base[i] == '+' || base[i] == '-')
			*error = 1;
		j = i + 1;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				*error = 1;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '%'
				|| base[i] == '/' || base[i] == '*' || base[i] == '='
				|| base[i] == ',' || base[i] == '.'
				|| base[i] < 33 || base[i] > 126)
			*error = 1;
		else
			i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		error;
	long	temp_nbr;

	base_len = 0;
	error = 0;
	base_check(base, &error);
	temp_nbr = nbr;
	if (error == 0)
	{
		if (nbr < 0)
		{
			temp_nbr *= -1;
			write(1, "-", 1);
		}
		while (base[base_len])
			base_len++;
		if (temp_nbr < base_len)
			ft_putchar(base[temp_nbr]);
		if (temp_nbr >= base_len)
		{
			ft_putnbr_base(temp_nbr / base_len, base);
			ft_putnbr_base(temp_nbr % base_len, base);
		}
	}
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int ac, char *ag[])
{
	if(ac > 0)
	{
		char base[] = "0123456789ABCDEF";
		int x = atoi(ag[1]);
		ft_putnbr_base(x, base);
	}
	return 0;
}