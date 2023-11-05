/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:02:24 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 10:44:31 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i++] = '\0';
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[10] = "abcdefghi";
	char dest[10];
	printf("ft_strncpy:%s\n", ft_strncpy(dest, str, 5));
	strcpy(dest, "");
	printf("strnpy:%s\n", strncpy(dest, str, 5));
	return (0);
}*/
