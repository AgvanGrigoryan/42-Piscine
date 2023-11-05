/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:45:31 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/14 18:16:05 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive_print(int nb)
{
	char	k;

	if (nb == 0)
		return ;
	if (nb < 0)
	{	
		write(1, "-", 1);
		nb *= -1;
	}
	k = '0' + nb % 10;
	if (nb > 0)
		recursive_print(nb / 10);
	write(1, &k, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else if (nb <= -2147483648)
		write(1, "-2147483648", 11);
	else
		recursive_print(nb);
}
