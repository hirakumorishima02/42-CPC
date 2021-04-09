/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 06:44:51 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/03 09:37:36 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (src[i] != '\0')
		dest[i++] = src[c++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *dest;

	if (src[0] == '\0')
		return (0);

	dest = (char*)malloc(sizeof(src));

	if (dest)
		ft_strcpy(dest, src);
	return (dest);
}

int	main()
{
	char src[] = "AAAAAAAAAA";
	char *dest = ft_strdup(src);
	char *dest2 = ft_strdup(src);
	printf("%s\n", dest);
	printf("%s\n", dest2);
	return (0);
}