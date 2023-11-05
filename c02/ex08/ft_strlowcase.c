/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:26:18 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 10:32:09 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UPP_LOW_DIFF 32

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += UPP_LOW_DIFF;
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int main(void)
{
    char str[10] = "ABCdef12+";
    printf("str before:\t%s\n", str);
	printf("str after:\t%s", ft_strlowcase(str));
    return (0);
}*/
