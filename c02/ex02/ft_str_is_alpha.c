/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:35:27 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 10:42:03 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
			return (0);
		str++;
	}
	return (1);
}
/*#include <stdio.h>
int	main(void)
{
	char right_str[10] = "adsfjKGks";
	char wrong_str[10] = "asd67dkla";
	printf("len=0,wrong_str[%s],right_str[%s]\n", wrong_str, right_str);
	printf("len=0:%d,\n", ft_str_is_alpha(""));
	printf("wrong_str:%d,\n", ft_str_is_alpha(wrong_str));
	printf("right_str:%d\n", ft_str_is_alpha(right_str));
	return (0);
}*/
