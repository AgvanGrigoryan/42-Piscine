/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:20:26 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/14 17:40:15 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

void	swap_string(char **ptr1, char **ptr2)
{
	char	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

void	ft_sort_string_tab(char **tab)
{
	int		swapped;
	int		i;
	int		j;

	i = 0;
	while (tab[i + 1])
	{
		swapped = 0;
		j = 1;
		while (tab[i + j + 1])
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				swap_string(tab + j, tab + j + 1);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	(void)argc;
	ft_sort_string_tab(argv);
	for (int i = 1; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}*/
