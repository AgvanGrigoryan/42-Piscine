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
#include <unistd.h>

int	is_numeric(char chr)
{
	return ('0' <= chr && chr <= '9');
}

int	ft_atoi(char *str)
{
	int				res;
	unsigned int	i;
	int				sign;

	sign = 1;
	i = 0;
	res = 0;

	if (str[i] && str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
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
void	ft_putchar(char chr)
{
	write(1, &chr, 1);
}
int	is_zero(int num, char *msg)
{
	if (num == 0)
	{
		while (*msg)
			write(1, msg++, 1);
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

void	ft_calc(char *value1, char sign, char *value2)
{
	int num1;
	int	num2;

	num2 = ft_atoi(value2);
	num1 = ft_atoi(value1);
	switch (sign)
	{
		case '+':
			ft_putnbr(num1 + num2);
			break;
		case '-':
			ft_putnbr(num1 - num2);
			break;
		case '*':
			ft_putnbr(num1 * num2);
			break;
		case '/':
			if (is_zero(num2,"Stop : division by zero"))
				break ;
			ft_putnbr(num1 / num2);
			break;
		case '%':
			if (is_zero(num2, "Stop : module by zero"))
				break ;
			ft_putnbr(num1 % num2);
			break;
		default:
			write(1, "0", 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	ft_calc(argv[1], *(argv[2]), argv[3]);
}