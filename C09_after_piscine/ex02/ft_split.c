/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:26:45 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/31 13:03:17 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	is_separator(char chr, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == chr)
			return (true);
		i++;
	}
	return (false);
}

int	count_words(char *str, char *charset)
{
	int				i;
	unsigned int	count;
	bool			is_first_of_word;

	i = 0;
	count = 0;
	is_first_of_word = true;
	while (str[i])
	{
		if (is_separator(str[i], charset))
		{
			is_first_of_word = true;
			i++;
			continue ;
		}
		else if (is_first_of_word && !is_separator(str[i], charset))
			count++;
		is_first_of_word = false;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *src, long int src_len)
{
	char			*mem;
	unsigned int	i;

	i = 0;
	if (*src == '\0')
		return (NULL);
	mem = (char *)malloc(src_len + 1);
	if (mem == NULL)
		return (NULL);
	while (i < src_len && *src)
	{
		mem[i] = src[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

bool	separate_words(char *str, char *charset,
		char **string_arr, unsigned int word_count)
{
	unsigned int	i;
	char			*word_start;

	i = 0;
	while (str && i < word_count)
	{
		while (is_separator(*str, charset))
			str++;
		if (!is_separator(*str, charset))
			word_start = str;
		while (*str && !is_separator(*str, charset))
			str++;
		string_arr[i] = ft_strdup(word_start, (str) - word_start);
		if (string_arr[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}

char	**ft_split(char *str, char *charset)
{
	char			**string_arr;
	unsigned int	word_count;

	word_count = count_words(str, charset);
	string_arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (string_arr == NULL)
		return (NULL);
	if (!separate_words(str, charset, string_arr, word_count))
		return (NULL);
	string_arr[word_count] = 0;
	return (string_arr);
}
/*int	main(void)
{
	char **res;
	//res = ft_split("  123   abg hhhhhhh l kjkl   iij \tlskd", "empty");
	
	res = ft_split("agvan grigoryannn oopaag", "gggo");
	
	for(int i = 0; res[i]; i++)
	{
		printf("'%s'\n", res[i]);
		free(res[i]);
	}
	free(res);
	return (0);
}*/
