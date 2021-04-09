/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 07:04:01 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/03 09:32:00 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int *array;
	int i;
	if (min > max || min == max)
		return (0);
	array = (int*)malloc(sizeof(array) * (max - min));

	i = 0;

	while(min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	int *array = ft_range(min, max);
	int i = 0;
	while(i < max - min)
	{
		printf("%d\n", array[i]);
		i++;
	}	
	}
	return 0;
}