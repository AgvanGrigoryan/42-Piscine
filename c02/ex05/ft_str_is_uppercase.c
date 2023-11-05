/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:27:37 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 10:37:44 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
			return (0);
		str++;
	}
	return (1);
}
/*#include <stdio.h>
int main(void)
{
    char right_str[10] = "ABCDEFGHI";
    char wrong_str[10] = "ABCDeFGHI";
    printf("empty:\"\",wrong_str[%s],right_str[%s]\n", wrong_str, right_str);
    printf("empty:%d,\n", ft_str_is_uppercase(""));
    printf("wrong_str:%d,\n", ft_str_is_uppercase(wrong_str));
    printf("right_str:%d\n", ft_str_is_uppercase(right_str));
    return (0);
}*/
