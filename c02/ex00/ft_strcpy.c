/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:15:35 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 13:37:14 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	src[13] = "Is it works?";
	char	src1[13] = "Is it works?";
	char	dest[13];
	printf("ft_strcpy:%s\n", ft_strcpy(dest, src));
	strcpy(dest, "");
	printf("strcpy:%s\n", strcpy(dest, src1));
	return (0); 
}*/
