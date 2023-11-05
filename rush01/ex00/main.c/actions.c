/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genavasa <genavasa@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:30:56 by genavasa          #+#    #+#             */
/*   Updated: 2023/10/22 23:37:44 by genavasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int	add_floor(int *floor, int *i, int *j)
{
	if (*floor < 4)
	{
		*floor += 1;
		return (1);
	}
	else
		*floor = 0;
	if (j > 0)
	{
		*j -= 1;
		return (0);
	}
	else
	{
		*i -= 1;
		*j = 3;
		return (0);
	}
}

void	zero_fill(int **map, int map_sz)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_sz)
	{
		j = 0;
		while (j < map_sz)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	is_zeros(int line[4], int map_sz)
{
	int	i;

	i = 0;
	while (i < map_sz)
	{
		if (line[i] == 0)
			return (1);
		i++;
	}
	return (0);
}
