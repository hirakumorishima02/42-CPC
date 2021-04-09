/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:18:11 by gmatsumo          #+#    #+#             */
/*   Updated: 2021/03/12 17:34:50 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	while (src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	*dest = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int a;
	int length;
	char *result;
	int b;

	a = 0;
	b = 0;
	i = 0;
	length = 0;
	if (size == 0)
	{
		result = (char *)malloc(1);
		*result = 0;
		return (result);
	}
	while (i < size)
		length += ft_strlen(strs[i++]);
	length += (ft_strlen(sep) * (size - 1));
	result = (char *)malloc(sizeof(char) * (length + 1));
	*result = 0;
	while (a < size)
	{
		result = ft_strcat(result, strs[a]);
		if (a < size - 1)
			result = ft_strcat(result, sep);
		a++;
	}
	result[a] = '\0';
	return (result);
}

int	main(int ac, char **ag)
{
	if (ac > 0)
	{
		int size = 5;
		char sep[] = "XXXX";
		printf("%s\n", ft_strjoin(size, ag, sep));
	}
	return (0);
}