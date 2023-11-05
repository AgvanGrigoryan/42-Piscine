/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:00:53 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/15 15:47:59 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*#include <stdio.h>
int	main(void)
{
	int	i = 0;
	int	nums[13] = {1, 54, 32, 6, 2, 5, -3, 494, 12, -12, 999, 84848, 7};
	ft_sort_int_tab(nums, 13);
	while (i < 13)
	{
		printf("%d,", nums[i]);
		i++;
	}
	return (0);
}*/
