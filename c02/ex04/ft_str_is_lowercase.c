/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:27:37 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 10:39:00 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		str++;
	}
	return (1);
}
/*#include <stdio.h>
int main(void)
{
    char right_str[10] = "abcdxyzup";
    char wrong_str[10] = "abcdPyzup";
    printf("empty:\"\",wrong_str[%s],right_str[%s]\n", wrong_str, right_str);
    printf("empty:%d,\n", ft_str_is_lowercase(""));
    printf("wrong_str:%d,\n", ft_str_is_lowercase(wrong_str));
    printf("right_str:%d\n", ft_str_is_lowercase(right_str));
    return (0);
}*/
