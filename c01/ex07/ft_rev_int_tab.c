/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:32:39 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/15 15:12:44 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	p;
	int	p_rev;
	int	tmp;

	p = (size / 2);
	while (p-- > 0)
	{
		p_rev = size - p - 1;
		tmp = tab[p];
		tab[p] = tab[p_rev];
		tab[p_rev] = tmp;
	}
}
/*
int	main(void)
{
	int	i = 0;
	int	int_arr[11] = {1,2,3,4,5,6,7,8,9,10,11};
	ft_rev_int_tab(int_arr, 11);
	while (i < 11)
		printf("%d,", int_arr[i++]);
	return (0);
}*/
