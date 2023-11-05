/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:03:40 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/25 11:37:01 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_l;
	unsigned int	src_l;
	unsigned int	i;

	i = 0;
	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (size <= dest_l)
		return (src_l + size);
	while (*dest)
		dest++;
	while (i < size - dest_l - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest_l + src_l);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "fight fire with sdffire";
	char dest[60] = "agvan ";
	char dest2[60] = "agvan ";
	printf("mine:%u\n", ft_strlcat(dest, str, 60));
	printf("orig:%lu\n", strlcat(dest2, str, 60));
	return (0);
}*/
