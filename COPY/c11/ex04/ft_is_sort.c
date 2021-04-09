/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 07:47:24 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/12 10:42:19 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int diff;

	i = 1;
	diff = f(tab[0], tab[1]) < 0 ? 1 : 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) == 0)
			continue ;
		else if (f(tab[i], tab[i + 1]) < 0 && !diff)
			return (0);
		else if (f(tab[i], tab[i + 1]) > 0 && diff)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>
int f(int a, int b){
	return (a - b);
}

int main(){
	int arry[] = {5,3,4};
	printf("%d\n", ft_is_sort(arry, 3, f));
	return 0;
}
