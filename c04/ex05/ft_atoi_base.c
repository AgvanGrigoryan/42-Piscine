/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:02:08 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/27 15:09:29 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_in_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	base_l;

	base_l = 0;
	while (base[base_l])
		base_l++;
	i = 0;
	j = 0;
	if (!base || base_l == 1)
		return (0);
	while (i < base_l)
	{
		j = 0;
		while (j < base_l)
		{
			if (i != j)
				if (base[i] == '+' || base[i] == '-'
					|| base[i] == ' ' || base[i] == base[j])
					return (0);
			j++;
		}
		i++;
	}
	return (base_l);
}

void	count_number(char *str, char *base, int base_l, int *res)
{
	int	number;

	number = 0;
	while (*str && is_in_base(*str, base))
	{
		while (base[number] && base[number] != *str)
			number++;
		*res *= base_l;
		*res += number;
		str++;
		number = 0;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int				res;
	int				base_l;
	int				sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	base_l = is_valid_base(base);
	if (!base_l)
		return (0);
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	count_number(str + i, base, base_l, &res);
	return (res * sign);
}
/*#include <stdio.h>
int	main(void)
{
	char str[] = "+----+-+16s";
	//char base2[] = "01";
	char base8[] = "01234567";
	//char base10[] = "0123456789";
	//char base16[] = "0123456789abcdef";
	printf("%d\n", ft_atoi_base(str, base8));
}*/
