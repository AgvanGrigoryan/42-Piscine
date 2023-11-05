/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:37:14 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/31 21:32:03 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

void	ft_strncpy(char *dst, char *src, unsigned int src_l)
{
	unsigned int	i;

	i = 0;
	while (i < src_l && *src)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *src)
{
	char			*mem;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	mem = (char *)malloc(sizeof(char) * src_len + 1);
	if (mem == NULL)
		return (NULL);
	ft_strncpy(mem, src, src_len);
	return (mem);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *mem;
	char str[] = "abcdef";
	mem = ft_strdup(str);
	printf("%s\n", mem);
	free(mem);
	mem = strdup(str);
	printf("%s\n", mem);
	free(mem);
}*/
