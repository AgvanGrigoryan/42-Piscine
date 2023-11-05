/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phrase_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:56:33 by sosokin           #+#    #+#             */
/*   Updated: 2023/10/29 22:48:49 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phrase_builder.h"

char	*create_phrase(char *first, char *second, char *sep)
{
	int		len;
	char	*str;

	len = ft_strlen(first);
	len += ft_strlen(second);
	len += ft_strlen(sep);
	str = malloc((len + 1) * sizeof(char));
	*str = 0;
	str = ft_strcat(str, first);
	str = ft_strcat(str, sep);
	str = ft_strcat(str, second);
	return (str);
}

char	*get_hundreds(int h_ind, char *str, char ***dict)
{
	char	*first;
	char	*second;
	char	*phrase;
	int		cur_char;

	cur_char = str[h_ind] - '0';
	if (cur_char == 0)
		return (NULL);
	first = dict[0][cur_char];
	second = dict[3][0];
	phrase = create_phrase(first, second, " ");
	return (phrase);
}

char	*get_tens(int t_ind, char *str, char ***dict, int ind)
{
	char	*first;
	char	*second;
	char	*phrase;
	int		cur_char;

	cur_char = str[t_ind] - '0';
	if (cur_char == 0)
		return (NULL);
	if (cur_char == 1)
	{
		cur_char = str[ind] - '0';
		first = dict[1][cur_char];
		return (create_phrase(first, "", ""));
	}
	else
	{
		cur_char -= 2;
		first = dict[2][cur_char];
		second = get_singles(ind, str, dict);
		if (second == NULL)
			return (create_phrase(first, "", ""));
	}
	phrase = create_phrase(first, second, "-");
	return (phrase);
}

char	*get_singles(int ind, char *str, char ***dict)
{
	int		cur_char;

	cur_char = str[ind] - '0';
	if (cur_char == 0 && ind > 0)
		return (NULL);
	return (create_phrase("", dict[0][str[ind] - '0'], ""));
}
