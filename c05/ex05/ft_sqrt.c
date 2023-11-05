/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:41:56 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/26 18:34:03 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	k;

	i = 1;
	if (nb == 1)
		return (1);
	else if (nb < 0)
		return (0);
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
/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_sqrt(2147483647));
}*/
