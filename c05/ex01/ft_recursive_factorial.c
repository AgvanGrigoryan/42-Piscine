/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:12:44 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/25 11:58:32 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = 0;
	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	else if (nb > 1)
		res = nb * ft_recursive_factorial(nb - 1);
	return (res);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_recursive_factorial(-1));
}*/
