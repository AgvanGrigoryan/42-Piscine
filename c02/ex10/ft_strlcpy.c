/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:45:47 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 22:22:21 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (i);
}
/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char dest[15];
	char src[15] = "abcdefghijklmo";
	printf("returned:%d,%s\n", ft_strlcpy(dest, src, 15), dest);
	char	dest2[15];
	printf("returned:%d,%s\n", ft_strlcpy(dest2, src, 15), dest2);
	return (0);
}*/
