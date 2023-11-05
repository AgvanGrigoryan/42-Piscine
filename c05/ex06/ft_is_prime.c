/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:11:56 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/26 18:35:03 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	k;

	i = 1;
	if (nb == 1)
		return (1);
	k = nb / 2;
	while (i <= k)
	{
		if (i >= 46341)
			return (0);
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	k;
	int	i;

	if (nb <= 1)
		return (0);
	k = ft_sqrt(nb);
	if (k == 0)
		k = nb / 2;
	i = 2;
	while (i <= k)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*#include <stdio.h>
int	main(void)
{
	for (int i = 1; i < 500; i++)
	{
		if (ft_is_prime(i))
			printf("%d\n", i);
	}
}*/
