/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:16:12 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/15 13:18:13 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*#include <stdio.h>
int	main(void)
{
	int a = 27, b = 7, div, mod;
	ft_div_mod(a, b, &div, &mod);
	printf("%d %d, div=%d, mod=%d", a, b, div, mod);
	return (0);
}*/
