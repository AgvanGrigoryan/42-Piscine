/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:01:27 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 10:33:21 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UPP_LOW_DIFF 32

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= UPP_LOW_DIFF;
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int main(void)
{
    char str[10] = "ab c+def";
    printf("str before:%s\n", str);
	printf("str after:%s", ft_strupcase(str));
    return (0);
}*/
