/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:47:19 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/12 20:06:56 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(const int *num)
{
	char	fd;
	char	ld;

	fd = '0' + *num / 10;
	ld = '0' + *num % 10;
	write(1, &fd, 1);
	write(1, &ld, 1);
}

void	print_two_two_digits(const int *a, const int *b)
{
	print_num(a);
	write(1, " ", 1);
	print_num(b);
	if (*a != 100 - 2 || *b != 100 - 1)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			print_two_two_digits(&a, &b);
			b++;
		}
		a++ ;
	}
}
