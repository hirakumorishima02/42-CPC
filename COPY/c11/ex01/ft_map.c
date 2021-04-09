/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:10:57 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/11 16:38:32 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int	*arry;

	arry = (int*)malloc(sizeof(int) * length);
	if (!arry)
		return (arry);
	i = 0;
	while (i < length)
	{
		f(tab[i]);
		arry[i] = tab[i];
		i++;
	}
	return (arry);
}

int nanimoshinai(int a){
  return (a * 2);
}

int main(){
  int tab[] = {1,2,3,4,5};
  int *arry;
  ft_map(tab, 3, nanimoshinai));
  return (0);
}
