/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:44:50 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/04 11:23:23 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lowcase(char *str, int *p)
{
	char c;

	c = str[*p];
	while ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
	{
		if (c > 64 && c < 91)
		{
			str[*p] = str[*p] + 32;
		}
		(*p)++;
		c = str[*p];
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
		{
			str[i] = str[i] - 32;
			i++;
			ft_lowcase(str, &i);
		}
		else if ((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91))
		{
			i++;
			ft_lowcase(str, &i);
		}
		else
		{
			i++;
		}
	}
	return (str);
}

#include <stdio.h>
int main(void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(str));
	return 0;
}