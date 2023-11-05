/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genavasa <genavasa@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:32:25 by genavasa          #+#    #+#             */
/*   Updated: 2023/10/22 23:32:28 by genavasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "rush01.h"
#include "validate.h"
#include "print_map.h"
#include "actions.h"
#define SIZE 4

bool is_safe(int **map, int i, int j, int vis_builds[16])
{
	int cnt_arr[2];

	cnt_arr[0] = 1;
	cnt_arr[1] = 1;
	if (!is_dubl(map, i, j))
		return (false);
	if (j == SIZE - 1 )
	{
		if (!seems_horizontal(map[i], cnt_arr, vis_builds))
			return (false);
	}
	else if (i == SIZE - 1)
	{
		if (!seems_vertical(j, map, cnt_arr, vis_builds))
			return (false);
	}
	return (true);
}

void	calc_i_j(bool add, int *i, int *j)
{
	if (add)
	{
		if (*j < SIZE - 1)
			*j += 1;
		else if (*i < SIZE - 1)
		{
			*j = 0;
			*i += 1;
		}
	}
	else
	{
		if (*j > 0)
			*j -= 1;
		else if (*i < SIZE - 1)
		{
			*j = SIZE - 1;
			*i -= 1;
		}
	}
}
bool solving(int **map, int vis_builds[16], int i, int j)
{
	int	k;

	k = 0;
    while (k < 4)
    {
		map[i][j] = k;
    	if (is_safe(map, i, j, vis_builds))
    	{
			calc_i_j(true, &i, &j);
			if (solving(map, vis_builds, i, j))
				return (true);
		}
		k++;
    }
	calc_i_j(false, &i, &j);
    return (false);
}

int is_right_nums(int nums[16], unsigned int num_cnt)
{
	unsigned int    i;
	unsigned int    max;

	max = 4;
	i = 0;
	while(i < num_cnt)
	{
		if (nums[i] < 1 || nums[i] > max)
		{
			write(1, "(Wrong numbers count): ", 23);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < max)
	{
		if(((nums[i] + nums[i + 4] > max + 1) || (nums[i] + nums[i + 4] < 3))
		   || ((nums[i + 8] + nums[i + 12] > max + 1) || (nums[i + 8] + nums[i + 12] < 3)))
		{
			write(1, "(Wrong number combination): ", 28);
			return (0);
		}
		i++;
	}
	return (1);
}
// return 1 if input is correct otherwise 0
int    is_right_input(char *sym, int nums[16], unsigned int *num_cnt)
{
	int format;
	unsigned int i;

	format = 1;
	i = 0;
	*num_cnt = 0;
	while (sym[i])
	{
		if ((i % 2 != 0 && sym[i] != ' ')
			|| (i % 2 == 0 && !('0' <= sym[i] && sym[i] <= '9')))
		{
			format = 0;
			break;
		} else if (sym[i] != ' ') {
			nums[*num_cnt] = (unsigned int) sym[i] - '0';
			(*num_cnt)++;
		}
		i++;
	}
	if (!is_right_nums(nums, *num_cnt) || !format || *num_cnt < 16 || *num_cnt % 4 != 0) // 16 is minimal count of input numbers
	{
		write(1, "Invalid Input\n", 14);
		return (0);
	}
	return (1);
}



