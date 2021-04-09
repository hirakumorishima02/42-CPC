/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:55:50 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/11 16:05:32 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;

	i = 0;
	while (i < length)
	{
		f(*tab++);
		i++;
	}
	return ;
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = nb * -1;
		}
		if (nb <= 9)
		{
			c = nb + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(nb / 10);
			c = nb % 10 + '0';
			write(1, &c, 1);
		}
	}
}

int	main(void)
{
	int tab[] = {1,2,3,4,5};
	ft_foreach(tab, 4, &ft_putnbr);
	return (0);
}