/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:33:39 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/19 18:33:15 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char str)
{
	return (32 <= str && str <= 126);
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	chr;
	char			*hex;
	int				i;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			ft_putchar(str[i]);
		else
		{
			chr = (unsigned char) str[i];
			ft_putchar('\\');
			ft_putchar(hex[chr / 16]);
			ft_putchar(hex[chr % 16]);
		}
		i++;
	}
}
/*int	main(void)
{
	char str[] = {'a','\n', 'B', -36, 'f', '\0'};
	ft_putstr_non_printable(str);
}*/
