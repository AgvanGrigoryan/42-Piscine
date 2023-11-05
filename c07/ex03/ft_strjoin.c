/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:30:31 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/31 12:32:21 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	count_total_len(char *sep, char **strs, int size)
{
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	while (i < size)
		sum += ft_strlen(strs[i++]);
	if (size > 1)
		sum += ft_strlen(sep) * (size - 1);
	return (sum + 1);
}

void	join(char *res, int size, char **strs, char *sep)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		while (*strs[i])
		{
			*res++ = *strs[i];
			strs[i]++;
		}
		i++;
		j = 0;
		while (i < size && sep[j])
		{
			*res++ = sep[j];
			j++;
		}
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_str_len;
	char	*res;
	int		i;

	i = 0;
	total_str_len = count_total_len(sep, strs, size);
	res = (char *)malloc(total_str_len);
	if (res == NULL)
		return (0);
	if (size == 0)
		*res = '\0';
	else
	{
		join(res, size, strs, sep);
		res[total_str_len - 1] = '\0';
	}
	return (res);
}
/*int	main(void)
{
	char *strs[] = {"abc", "qwerty", "aaa", "349"};
	char sep[] = "--";
	char *res = ft_strjoin(4, strs, sep);
	printf("%s\n", res);
	free(res);
}*/
