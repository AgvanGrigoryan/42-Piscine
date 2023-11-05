/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:37:43 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 10:35:19 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || 126 < *str)
			return (0);
		str++;
	}
	return (1);
}
/*#include <stdio.h>
int main(void)
{
    char right_str[10] = "abc *123A";
    char wrong_str[10] = "abc /\nbbA";
    printf("empty:\"\",wrong_str[%s],right_str[%s]\n", wrong_str, right_str);
    printf("\nempty:%d,\n", ft_str_is_printable(""));
    printf("wrong_str:%d,\n", ft_str_is_printable(wrong_str));
    printf("right_str:%d\n", ft_str_is_printable(right_str));
    return (0);
}*/
