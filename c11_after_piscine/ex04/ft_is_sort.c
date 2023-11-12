/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:20:26 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/11 19:24:15 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	ft_numcmp(int a, int b)
{
	return (a - b);
}
*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	is_asc;
	int	i;

	i = 0;
	is_asc = 0;
	if (length <= 2)
		return (1);
	if ((*f)(tab[0], tab[length - 1]) < 0)
		is_asc = 1;
	while (i < length - 1)
	{
		if (!((is_asc && (*f)(tab[i], tab[i + 1]) <= 0)
			|| (!is_asc && (*f)(tab[i], tab[i + 1]) >= 0)))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	int	arr[] = {5};
	int	arr_len = sizeof(arr) / sizeof(arr[0]);
	printf("arr_len:%d\n", arr_len);
	printf("IS_SORTED:%d\n", ft_is_sort(arr, arr_len, &ft_numcmp));
	return (0);
}*/
