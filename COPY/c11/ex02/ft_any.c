/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:41:56 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/11 16:53:44 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i++]) != 0)
			return (1);
	}
	return (0);
}

int f(char *s)
{
	while(*s)
		s++;
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc > 0)
		printf("%d\n", ft_any(argv,f));
	return (0);
}