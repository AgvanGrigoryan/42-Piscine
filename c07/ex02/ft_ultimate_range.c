/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:27:19 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/31 12:03:22 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	mem_len;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	mem_len = max - min;
	*range = (int *)malloc(sizeof(int) * mem_len);
	if (*range == NULL)
		return (-1);
	while (i < mem_len)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (mem_len);
}
/*#include <stdio.h>
int	main(void)
{
	int	*range;
	int	min;
	int	max;
	int	range_len;
	int	i;

	i = 0;
	min = 10;
	max = 17;
	range_len = ft_ultimate_range(&range, -76, -75);
	printf("range len: %d\n", range_len);
	while (i < range_len)
		printf("%d ", range[i++]);
	free(range);
	return (0);
}*/
