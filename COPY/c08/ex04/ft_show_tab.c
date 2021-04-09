/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 06:13:12 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/06 06:54:45 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"
struct			s_stock_str *ft_strs_to_tab(int ac, char **av);

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	num(int nb)
{
	char c;

	c = nb + 48;
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		num(nb);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		putstr(par[i].str);
		write(1, "\n", 1);
		putnbr(par[i].size);
		write(1, "\n", 1);
		putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
}