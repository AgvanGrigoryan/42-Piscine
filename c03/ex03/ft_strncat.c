/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:37:17 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/19 14:04:30 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < nb && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[10] = "grigoryan";
	char dest1[20] = "agvan";
	char dest2[20] = "agvan";
	printf("%s\n", ft_strncat(dest1, str, 15));
	printf("%s", strncat(dest2, str, 15));
}*/
