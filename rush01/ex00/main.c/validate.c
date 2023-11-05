/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genavasa <genavasa@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:32:48 by genavasa          #+#    #+#             */
/*   Updated: 2023/10/22 23:32:51 by genavasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#define SIZE 4

bool is_dubl(int **map, int i, int j)
{
    int k;

    k = 0;
    while (k < 4) {
        if (k != j && k != i)
		{
            if (map[i][k] == 0)
				break;
            if (map[i][j] == map[i][k] || map[i][j] == map[k][j])
                return (false);
		}
		k++;
    }
    return (true);
}
bool seems_horizontal(int *line, int cnt_arr[2], int vis_builds[16])
{
	int max;
	int max2;
	int i;

	max = line[0];
	max2 = line[SIZE - 1];
	i = 1;
	while (i < SIZE)
	{
		if (line[i] > max)
		{
			max = line[i];
			cnt_arr[0]++;
		}
		if (line[SIZE - i - 1] > max2)
		{
			max2 = line[SIZE - i - 1];
			cnt_arr[1]++;
		}
		i++;
	}
	if (cnt_arr[0] != vis_builds[i + 8] || cnt_arr[1] != vis_builds[i + 12])
		return (false);
	return (true);
}
bool seems_vertical(int j, int **map, int cnt_arr[2], int vis_builds[16])
{
	int max;
	int max2;
	int i;

	i = 1;
	max = map[0][j];
	max2 = map[SIZE - 1][j];
	while (i < SIZE)
	{
		if (map[i][j] > max)
		{
			max = map[i][j];
			cnt_arr[0]++;
		}
		if (map[SIZE - i - 1][j] > max2)
		{
			max2 = map[SIZE - i - 1][j];
			cnt_arr[1]++;
		}
		i++;
	}
	if (cnt_arr[0] != vis_builds[i] || cnt_arr[1] != vis_builds[i + 4])
		return (false);
	return (true);
}
