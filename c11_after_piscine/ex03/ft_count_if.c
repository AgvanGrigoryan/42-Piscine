/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:20:26 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/11 19:24:15 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
int	is_a(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
		{

			printf("STRING:%s\nLETTER:%s\n", str, str+i);
			return (1);
		}
		i++;
	}
	return (0);
}*/
int	ft_count_if(char **tab, int length, int (*f)(char *))
	{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < length && tab[i])
	{
		if ((*f)(tab[i]))
		{
			count++;
		}
		i++;
	}
	return (count);
}
/*
int	main(void)
{
char *arr[] = {"lolo", "ejan xndzor", "garo", "tiko", "vzgo", 0};
int arr_len = sizeof(arr) / sizeof(arr[0]);
printf("====RESULT===\n\%d\n", ft_count_if(arr, arr_len , &is_a));
return (0);
}*/
