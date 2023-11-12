/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:20:26 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/11 19:24:15 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*modified_arr;
	int	i;

	i = 0;
	modified_arr = (int *)malloc(sizeof(int) * length);
	if (!modified_arr)
		return (NULL);
	while (i < length)
	{
		modified_arr[i] = (*f)(tab[i]);
		i++;
	}
	return (modified_arr);
}
/*int	main(void)
{
	int	arr[] = {1, 2, 3, 222, -678, 0, -1, -45, 123456};
	int	arr_len = sizeof(arr) / sizeof(arr[0]);

	int *arr2 = ft_map(arr, arr_len, &ft_abs);
	for (int i = 0; i < arr_len; i++)
	{
		ft_putnbr(arr2[i]);
		ft_putchar('\n');
	}
	return (0);
}*/
