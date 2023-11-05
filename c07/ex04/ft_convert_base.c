/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:47:09 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/31 13:55:07 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*change_num_base(int num, char *base_to, int base_to_l);

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				num;
	int				base_from_l;
	int				base_to_l;
	int				sign;
	unsigned int	i;

	num = 0;
	sign = 1;
	i = 0;
	base_from_l = is_valid_base(base_from);
	base_to_l = is_valid_base(base_to);
	if (!base_from_l || !base_to_l)
		return (NULL);
	while ((9 <= nbr[i] && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] && (nbr[i] == '-' || nbr[i] == '+'))
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	count_number(nbr + i, base_from, base_from_l, &num);
	return (change_num_base(num * sign, base_to, base_to_l));
}
/*#include <stdio.h>
int	main(void)
{
	char str[] = "+--+-+0s";
	char base2[] = "01";
	char base8[] = "01234567";
	//char base10[] = "0123456789";
	//char base16[] = "0123456789abcdef";
	printf("%s\n", ft_convert_base(str, base2, base8));
}*/
