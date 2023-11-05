/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:24:07 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/29 20:30:40 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../inc/validate_dict.h"
#include "../inc/check_funcs_for_dict.h"

int	fill_dict(char **dict_section, unsigned int n, char *str, unsigned int len)
{
	dict_section[n] = (char *) malloc(sizeof(char) * len + 1);
	if (!dict_section[n])
		return (0);
	ft_strncpy(dict_section[n], str, len);
	return (1);
}

int	place_str_in_dict(char ***dict, char *start,
	char *end, unsigned int line_num)
{
	int	len;

	len = (int)(end - start);
	if (line_num < 10)
		return (fill_dict(dict[0], line_num, start, len));
	else if (line_num < 20)
		return (fill_dict(dict[1], line_num - 10, start, len));
	else if (line_num < 28)
		return (fill_dict(dict[2], line_num - 20, start, len));
	else if (line_num < 42)
		return (fill_dict(dict[3], line_num - 28, start, len));
	return (1);
}

int	parse_dict(char ***dict, char *buf, unsigned int *max_len)
{
	unsigned int	num_len;
	unsigned int	line_num;
	char			*start;
	int				i;

	start = NULL;
	i = 0;
	line_num = 0;
	while (buf[i])
	{
		num_len = 0;
		if (!check_format(buf, &i, &num_len, &start))
			return (0);
		if (!place_str_in_dict(dict, start, buf + i, line_num))
			return (0);
		if (num_len > *max_len)
			*max_len = num_len;
		i += 1;
		line_num++;
	}
	return (1);
}

char	***create_dict(void)
{
	char	***dict;
	int		i;
	int		sizes[4];

	sizes[0] = 10;
	sizes[1] = 10;
	sizes[2] = 8;
	sizes[3] = 13;
	i = 0;
	dict = (char ***)malloc(sizeof(char **) * 4);
	if (!dict)
		return (NULL);
	while (i < 4)
	{
		dict[i] = (char **)malloc(sizeof(char *) * sizes[i]);
		if (!dict[i])
			return (NULL);
		i++;
	}
	return (dict);
}

char	***check_dict(int descr, unsigned int *max_len)
{
	char	***dict;
	char	*buf;

	*max_len = 0;
	buf = (char *)malloc(800);
	if (!buf)
		return (NULL);
	read(descr, buf, 800);
	dict = create_dict();
	if (dict == NULL || parse_dict(dict, buf, max_len) == 0)
		return (NULL);
	return (dict);
}
