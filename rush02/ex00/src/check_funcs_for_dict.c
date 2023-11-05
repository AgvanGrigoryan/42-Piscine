/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs_for_dict.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:23:42 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/29 20:31:29 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/check_funcs_for_dict.h"

int	is_printable(char chr)
{
	return (32 <= chr && chr <= 126);
}

int	is_numeric(char chr)
{
	return ('0' <= chr && chr <= '9');
}

int	is_space(char chr)
{
	return (chr == '\t' || chr == '\n' || chr == '\v'
		|| chr == '\f' || chr == '\r' || chr == ' ');
}

char	*ft_strncpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_format(char *buf, int *i,
		unsigned int *num_len, char **start)
{
	if (!is_numeric(buf[*i]) || !buf[*i])
		return (0);
	while (is_numeric(buf[*i]) && buf[*i])
	{
		*i += 1;
		*num_len += 1;
	}
	while (is_space(buf[*i]) && buf[*i])
		*i += 1;
	if (buf[*i] != ':' || !buf[*i])
		return (0);
	else
		*i += 1;
	while (is_space(buf[*i]) && buf[*i])
		*i += 1;
	if (!is_printable(buf[*i]) || !buf[*i])
		return (0);
	else
		*start = buf + *i;
	while (is_printable(buf[*i]) && buf[*i] != '\n' && buf[*i])
		*i += 1;
	return (1);
}
