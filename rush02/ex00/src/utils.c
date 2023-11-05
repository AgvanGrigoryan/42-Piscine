/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:54:16 by sosokin           #+#    #+#             */
/*   Updated: 2023/10/29 22:54:40 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/utils.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = 0;
	return (dest);
}

void	write_phrase(char *phrase, int ind)
{
	int	len;

	len = ft_strlen(phrase);
	write(1, phrase, len);
	if (ind > 0)
		write(1, &" ", 1);
}

int	print_error(char *src)
{
	while (*src != '\0')
	{
		write(1, src, 1);
		++src;
	}
	return (0);
}

void	free_dict(char ***dict)
{
	int		i;
	int		j;
	int		sizes[4];

	sizes[0] = 10;
	sizes[1] = 10;
	sizes[2] = 8;
	sizes[3] = 13;
	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < sizes[i])
		{
			free(dict[i][j]);
		}
		free(dict[i]);
		i++;
	}
	free(dict);
}
