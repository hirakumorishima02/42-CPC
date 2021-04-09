/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:40:55 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/04 16:31:25 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int i;
	int *arry;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	arry = (int *)malloc(len * sizeof(int) + 1);
	if (arry == NULL)
	{
		*range = 0;
		return (-1);
	}
	while (i < len)
	{
		arry[i] = min + i;
		i++;
	}
	*range = arry;
	return (len);
}

int main(void)
{
	int *range;
	int min = 2;
	int max = 5;
	int result = ft_ultimate_range(&range, min, max);
	printf("range:%d\n", result);
	return (0);
}