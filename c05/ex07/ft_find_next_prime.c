/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:34:40 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/27 16:51:06 by aggrigor         ###   ########.fr       */
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
	i = 2;
	if (k == 0)
		k = nb / 2;
	while (i <= k)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (nb)
	{
		if (ft_is_prime(nb))
			break ;
		nb++ ;
	}
	return (nb);
}
/*#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_find_next_prime(7700));
}*/
