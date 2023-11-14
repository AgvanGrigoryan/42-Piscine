/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:20:26 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/11 19:24:15 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "utils.h"

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

int	is_zero(int num, char *msg)
{
	if (num == 0)
	{
		while (*msg)
		{
			ft_putchar(*msg);
			msg++;
		}
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		ft_putnbr(nb / 10);
		nb = -(nb % 10);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + (nb % 10));
	}
	else
		ft_putchar('0' + nb);
}

void	ft_calc(int num1, char sign, int num2)
{
	if (sign == '+')
		ft_putnbr(num1 + num2);
	else if (sign == '-')
		ft_putnbr(num1 - num2);
	else if (sign == '*')
		ft_putnbr(num1 * num2);
	else if (sign == '/')
	{
		if (!is_zero(num2, "Stop : division by zero"))
			ft_putnbr(num1 / num2);
	}
	else if (sign == '%')
	{
		if (!is_zero(num2, "Stop : modulo by zero"))
			ft_putnbr(num1 % num2);
	}
	else
		ft_putchar('0');
	ft_putchar('\n');
}

int	main(int argc, char *argv[])
{
	int	num1;
	int	num2;

	if (argc != 4)
		return (0);
	if (ft_strlen(argv[2]) > 1)
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
	else
	{
		num1 = ft_atoi(argv[1]);
		num2 = ft_atoi(argv[3]);
		ft_calc(num1, argv[2][0], num2);
	}
	return (0);
}
