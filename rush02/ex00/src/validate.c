/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyepremy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:14:35 by vyepremy          #+#    #+#             */
/*   Updated: 2023/10/29 22:57:24 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/validate.h"
#include <unistd.h>

void	ft_putstr(char *src, int descriptor)
{
	while (*src != '\0')
	{
		write(descriptor, src, 1);
		++src;
	}
}

unsigned int	validate_nb(char **arg, unsigned int max_len)
{
	unsigned int	i;
	char			*nb;

	i = 0;
	if (**arg == '+')
		*arg += 1;
	nb = *arg;
	if (nb[0] == '0' && nb[1] == '\0')
		return (1);
	if (nb[0] > '9' || nb[0] < '1')
		return (0);
	while (nb[i] != '\0')
	{
		if (nb[i] > '9' || nb[i] < '0')
			return (0);
		if (i >= max_len)
			return (0);
		++i;
	}
	return (i);
}
