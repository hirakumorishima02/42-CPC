/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:56:37 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/12 07:44:29 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if ((*f)(tab[i++]) != 0)
		{
			cnt++;
		}
	}
	return (cnt);
}

#include <stdio.h>
int f(char *s)
{
	while(*s)
	{
		s++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	if (argc > 0)
		printf("%d\n", ft_count_if(argv, 3, f));
	return (0);
}
