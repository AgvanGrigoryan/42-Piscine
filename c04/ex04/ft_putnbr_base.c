/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:01:22 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/25 11:13:25 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	fix_negative(int *div, int *mod)
{
	if (*div < 0)
		*div = *div * -1;
	if (*mod < 0)
		*mod = *mod * -1;
}

void	print_num(int num, char *base, int base_l)
{
	int		div;
	int		mod;

	div = num / base_l;
	mod = num % base_l;
	fix_negative(&div, &mod);
	if (div >= base_l)
		print_num(div, base, base_l);
	else
		write(1, &base[div], 1);
	write(1, &base[mod], 1);
}

int	is_valid_base(char *base, unsigned int base_l)
{
	unsigned int	i;
	unsigned int	j;

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
				if (base[i] == '+' || base[i] == '-' || base[i] == base[j])
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (!is_valid_base(base, base_len))
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	else
	{
		if (nbr < 0)
			write(1, "-", 1);
		print_num(nbr, base, base_len);
		write(1, "\n", 1);
	}
}
/*int	main(void)
{
	int num = 13;
	//char base2[] = "01";
	//char base8[] = "01234567";
	//char base10[] = "0123456789";
	char base16[] = "0123456789abcdef";
	ft_putnbr_base(num, base16);
}*/
