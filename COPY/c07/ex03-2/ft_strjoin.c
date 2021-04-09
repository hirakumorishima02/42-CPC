/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:32:20 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/05 08:31:27 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_free(char *str)
{
	str = (char *)malloc(sizeof(char));
	str = 0;
	return (str);
}

int		ft_len_total(char **strs, char *sep, int size)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i++]);
		if (i < size)
			len += ft_strlen(sep);
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*arr;

	len = 0;
	arr = 0;
	if (size <= 0)
		return (ft_free(arr));
	len = ft_len_total(strs, sep, size);
	arr = (char *)malloc(sizeof(char) * (len + 100));
	if (!arr)
		return (0);
	i = 1;
	*arr = 0;
	while (i < size)
	{
		arr = ft_strcat(arr, strs[i]);
		if (i < size - 1)
			arr = ft_strcat(arr, sep);
		i++;
	}
	return (arr);
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