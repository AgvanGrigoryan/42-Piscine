/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:22:20 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/31 13:54:21 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void	convert_base(int num, char *base_to, int base_to_l, char **res);

void	write_to_res(char c, char **res)
{
	**res = c;
	*res += 1;
}

void	fix_negative(int *div, int *mod)
{
	if (*div < 0)
		*div *= -1;
	if (*mod < 0)
		*mod *= -1;
}

char	*change_num_base(int num, char *base_to, int base_to_l)
{
	char	*res_num;
	char	*frst_chr;
	int		res_num_l;
	int		k;

	res_num_l = 0;
	k = num;
	while (k != 0)
	{
		res_num_l++;
		k /= base_to_l;
	}
	if (num < 0)
		res_num_l += 2;
	else
		res_num_l += 1;
	res_num = (char *)malloc(sizeof(char) * res_num_l);
	if (!res_num)
		return (NULL);
	*(res_num + res_num_l - 1) = '\0';
	frst_chr = res_num;
	convert_base(num, base_to, base_to_l, &frst_chr);
	return (res_num);
}

void	convert_base(int num, char *base_to, int base_to_l, char **res)
{
	if (num == INT_MIN)
	{
		convert_base(num / base_to_l, base_to, base_to_l, res);
		write_to_res(base_to[num % base_to_l], res);
	}
	if (num < 0)
	{
		write_to_res('-', res);
		num *= -1;
	}
	if (num < base_to_l)
		write_to_res(base_to[num], res);
	else if (num >= base_to_l)
	{
		convert_base(num / base_to_l, base_to, base_to_l, res);
		write_to_res(base_to[num % base_to_l], res);
	}
	else
		write_to_res(base_to[num % base_to_l], res);
}
