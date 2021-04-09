/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:17:35 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/04 06:58:39 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int sign_flag;
	int result;

	i = 0;
	sign_flag = 0;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign_flag++;
		i++;
	}
	sign_flag = sign_flag % 2 == 0 ? 1 : (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign_flag);
}

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	if(argc > 0)
	{
		printf("%d\n", ft_atoi(argv[1]));
	}
	return 0;
}