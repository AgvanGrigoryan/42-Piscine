/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:35:33 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/14 12:25:45 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	num_digs_init_fill(char *num, int *len)
{
	int	i;

	i = 0;
	while (i < *len)
	{
		num[i] = '0';
		i++;
	}
	num[i] = '\0';
}

void	print_num(char *num, int *len)
{
	char	fd_max_val;
	char	ajm;
	int		i;

	ajm = 0;
	i = 0;
	while (i < *len - 1)
	{
		if (num[i] >= num[i + 1])
		{
			ajm = 1;
			break ;
		}
		i++;
	}
	if (ajm == 0)
	{
		write(1, num, *len);
		fd_max_val = '0' + 10 - *len;
		if (num[0] != fd_max_val)
			write(1, ", ", 2);
	}
}

void	increase_num(char *num, int *len)
{
	int	k;

	k = (*len) - 1;
	while (k > 0)
	{
		num[k] += 1;
		if (num[k] > '9')
		{
			num[k] = '0';
			num[k - 1] += 1;
			k--;
		}
		print_num(num, len);
	}
}

void	ft_print_combn(int n)
{
	char	num[10];
	char	is_last_comb;

	num_digs_init_fill(num, &n);
	is_last_comb = 0;
	while (num[0] != '0' + 10 - n)
	{
		increase_num(num, &n);
	}
}

int	main(void)
{
	int	n;

	n = 3;
	ft_print_combn(n);
	return (0);
}
