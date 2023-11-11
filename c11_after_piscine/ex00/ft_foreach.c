/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:36:33 by agvan             #+#    #+#             */
/*   Updated: 2023/11/11 15:49:17 by agvan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}
/*int	main(void)
{
	int	arr[] = {1, 2, 3, 883, INT_MIN, 7654321, INT_MAX, 0, 13, 0, 777, 123};
	int	arr_len = sizeof(arr) / sizeof(arr[0]);

	ft_foreach(arr, arr_len, &ft_putnbr);
	write(1, "====================", 20);
	ft_foreach(arr, arr_len, &increase_num);

}*/
