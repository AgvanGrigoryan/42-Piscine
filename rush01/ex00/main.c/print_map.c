/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genavasa <genavasa@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:31:33 by genavasa          #+#    #+#             */
/*   Updated: 2023/10/22 23:31:36 by genavasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print_map.h"

void show_map(int **map, int n)
{
    int i;
    int j;
    int val;

    i = 0;
    while(i < n)
    {
        j = 0;
        while(j < n)
        {
            val = '0' + map[i][j];
            write(1, &val, 1);
            if (j != n - 1)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}
