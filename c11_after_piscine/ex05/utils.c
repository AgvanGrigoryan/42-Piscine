/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:20:26 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/11 19:24:15 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "utils.h"

int	is_numeric(char chr)
{
	return ('0' <= chr && chr <= '9');
}

int	is_space(unsigned char chr)
{
	return (chr == '\t' || chr == '\n' || chr == '\v'
		|| chr == '\f' || chr == '\r' || chr == ' ');
}

int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putchar(char chr)
{
	write(1, &chr, 1);
}
