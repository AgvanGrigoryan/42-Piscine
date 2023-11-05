/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izaitsev <izaitsev@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:19:24 by izaitsev          #+#    #+#             */
/*   Updated: 2023/10/15 11:54:55 by izaitsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_string(int len, char first, char middle, char end)
{
	int	char_counter;

	char_counter = 1;
	while (char_counter <= len)
	{
		if (char_counter == 1)
			ft_putchar(first);
		else if (char_counter == len)
			ft_putchar(end);
		else
			ft_putchar(middle);
		++char_counter;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	string_counter;

	string_counter = 1;
	if (x >= 1 && y >= 1)
	{
		while (string_counter <= y)
		{
			if (string_counter == 1)
				ft_print_string(x, '/', '*', '\\');
			else if (string_counter == y)
				ft_print_string(x, '\\', '*', '/');
			else
				ft_print_string(x, '*', ' ', '*');
			++string_counter;
		}
	}
}	
