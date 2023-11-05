/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:35:30 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/14 17:23:59 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_3_chars(char *x, char *y, char *z)
{
	write(1, x, 1);
	write(1, y, 1);
	write(1, z, 1);
	if (*x != '7' || *y != '8' || *z != '9')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				print_3_chars(&a, &b, &c);
				c++;
			}
			b++;
		}
		a++;
	}
}
