/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genavasa <genavasa@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:31:11 by genavasa          #+#    #+#             */
/*   Updated: 2023/10/22 23:31:13 by genavasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "print_map.h"
#include "rush01.h"
#include "actions.h"
#include "validate.h"

int **skyscrapers_start(char **argv);

int main(int argc, char *argv[])
{
	int **map;
	int i;
    if (argc != 2) {
        write(1, "Expected arguments(1) except for the executable filename\n", 57);
        return (0);
    }
    map = skyscrapers_start(argv);
	i = 0;
	while (i < 4)
	{
		free(map[i]);
		i++;
	}
	free(map);

    return (0);
}

int **skyscrapers_start(char **argv)
{
    int             **map;
    int			    vis_builds[16];
    unsigned int    num_cnt = 0;
    unsigned int    n;
    unsigned int	i;

    n = 4;
    if (!is_right_input(argv[1], vis_builds, &num_cnt))
        return (0);


    i = 0;
    map = (int**)malloc(4 * sizeof(int*));
    if (map == NULL)
    	return (0);
    while (i < 4)
	{
    	map[i] = (int*)malloc(4 * sizeof(int));
		if (map[i] == NULL)
			return (0);
    	i++;
	}


    zero_fill(map, n);
    if (!solving(map, vis_builds, 0, 0))
	{
    	write(1, "Lucum Chka", 10);
	}
    show_map(map, n);
    return (map);
}
