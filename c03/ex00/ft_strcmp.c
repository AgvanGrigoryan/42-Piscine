/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:27:09 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/19 17:47:58 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned int)*s1 - (unsigned int)*s2);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s1[] = "abcdaf";
	char s2[] = "abcdcf";
	printf("ft_strcmp:\t%d\n", ft_strcmp(0, 0));
	//printf("strcmp:\t\t%d\n", strcmp(0, 0));
	printf("ft_strcmp:\t\t%d\n", strcmp(s2, s1));
	printf("strcmp:\t\t%d\n", strcmp(s2, s1));

}*/
