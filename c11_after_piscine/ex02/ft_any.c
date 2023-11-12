/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:20:26 by agvan             #+#    #+#             */
/*   Updated: 2023/11/11 19:24:15 by agvan            ###   ########.fr       */
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
int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
/*int	main(void)
{
	char *arr[] = {"lolo", "ejan xndzor", "goro", "tiko", "vzgo", 0};
	printf("========RESULT========\n\t%d\t\n", ft_any(arr, &is_a));
	return (0);
}*/
