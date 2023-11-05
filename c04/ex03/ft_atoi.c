/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:14:17 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/25 11:16:20 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(char chr)
{
	return ('0' <= chr && chr <= '9');
}

int	is_space(unsigned char chr)
{
	return (chr == '\t' || chr == '\n' || chr == '\v'
		|| chr == '\f' || chr == '\r' || chr == ' ');
}

int	ft_atoi(char *str)
{
	int				res;
	unsigned int	i;
	int				sign;

	sign = 1;
	i = 0;
	res = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && is_numeric(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}
/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	printf("%d\n", ft_atoi(" \t--+-+-1234ab567"));
	printf("%d", atoi("1234ab567"));
}*/
