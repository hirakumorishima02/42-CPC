/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorishi <hmorishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:58:53 by hmorishi          #+#    #+#             */
/*   Updated: 2021/03/06 08:41:51 by hmorishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point point;
	set_point(&point);
	return (0);
}