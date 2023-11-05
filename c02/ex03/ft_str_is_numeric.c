/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:27:37 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 13:33:33 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
/*#include <stdio.h>
int main(void)
{
    char right_str[10] = "123456789";
    char wrong_str[10] = "123G56789";
    printf("empty:\"\",wrong_str[%s],right_str[%s]\n", wrong_str, right_str);
    printf("empty:%d,\n", ft_str_is_numeric(""));
    printf("wrong_str:%d,\n", ft_str_is_numeric(wrong_str));
    printf("right_str:%d\n", ft_str_is_numeric(right_str));
    return (0);
}*/
