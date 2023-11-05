/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:15:31 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 16:18:43 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define HEX_LEN 16
#define READABLE_MEMORY_LEN 16

void	ft_print_hex(char ch1, char ch2)
{
	write(1, &ch1, 1);
	write(1, &ch2, 1);
}

void	print_addr_as_hex(unsigned long long addr,
		const char *hexdigits)
{
	char	res[HEX_LEN];
	int		digit;
	int		i;

	i = 0;
	while (i < HEX_LEN)
		res[i++] = '0';
	i = HEX_LEN - 1;
	while (addr)
	{
		digit = addr & 0xf;
		res[i] = hexdigits[digit];
		i--;
		addr >>= 4;
	}
	i = 0;
	while (i < HEX_LEN)
		write(1, res + i++, 1);
	write(1, ": ", 2);
}

void	print_bytes_as_hex(unsigned char *addr,
		const char *hexdigits, unsigned int print_bytes)
{
	unsigned int	mem_val;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < READABLE_MEMORY_LEN)
	{
		j = 0;
		while (j < 2)
		{
			if (i >= print_bytes)
				write(1, "  ", 2);
			else
			{
				mem_val = *(addr + i + j);
				ft_print_hex(hexdigits[mem_val / 16], hexdigits[mem_val % 16]);
			}
			j++;
		}
		write(1, " ", 1);
		i += 2;
	}
}

void	ft_putstr_non_printable(unsigned char *addr, unsigned int print_bytes)
{
	unsigned int	i;

	i = 0;
	while (i < READABLE_MEMORY_LEN)
	{
		if (i >= print_bytes)
			write(1, " ", 1);
		else
		{
			if (32 <= addr[i] && addr[i] <= 126)
				write(1, addr + i, 1);
			else
				write(1, ".", 1);
		}
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	const char		*hexdigits;
	unsigned char	*mem_p;
	unsigned int	print_bytes;
	unsigned int	i;

	mem_p = addr;
	hexdigits = "0123456789abcdef";
	print_bytes = 16;
	i = 0;
	while (i < size)
	{
		print_addr_as_hex((unsigned long long int)(mem_p + i), hexdigits);
		print_bytes_as_hex(mem_p + i, hexdigits, print_bytes);
		ft_putstr_non_printable(mem_p + i, print_bytes);
		write(1, "\n", 1);
		i += 16;
		if ((size - i) < 16)
			print_bytes = size - i;
	}
	return (addr);
}
