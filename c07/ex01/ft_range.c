/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:54:25 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/31 11:54:07 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*range;
	unsigned int	range_len;
	unsigned int	i;

	if (min >= max)
	{
		return (NULL);
	}
	i = 0;
	range_len = max - min;
	range = (int *)malloc(range_len * sizeof(int));
	if (range == NULL)
		return (0);
	while (i < range_len)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*#include <stdio.h>
int	main(void)
{
	int min = -777;
	int	max = -555;
	int *range = ft_range(min, max);
	int i = 0;
	while (i < max - min)
		printf("%d, ", range[i++]);
	printf("\nlen: %d\n", i);
	free(range);
}*/
