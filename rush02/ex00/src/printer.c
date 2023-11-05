/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:02:17 by sosokin           #+#    #+#             */
/*   Updated: 2023/10/29 23:14:19 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/printer.h"
#include "../inc/phrase_builder.h"

void	add_suf(char **phrase, char *suf)
{
	char	*tmp;

	tmp = *phrase;
	*phrase = create_phrase(*phrase, suf, " ");
	free(tmp);
}

char	*set_phrase(char *first, char *second, int suf_ind, char ***dict)
{
	char	*phrase;

	if (first && second)
	{
		phrase = create_phrase(first, second, " and ");
		free(first);
		free(second);
	}
	else if (!first && second)
	{
		if (suf_ind == 0)
			phrase = create_phrase("", second, "and ");
		else if (suf_ind == -1)
			phrase = create_phrase("", second, "");
		else
			phrase = create_phrase("", second, "");
		free(second);
	}
	else if (first && !second)
		phrase = first;
	else
		return (NULL);
	if (suf_ind > 0)
		add_suf(&phrase, dict[3][suf_ind]);
	return (phrase);
}

void	write_and_free(char *phrase, int suf_ind)
{
	if (phrase)
	{
		write_phrase(phrase, suf_ind);
		free(phrase);
	}
}

void	show_numb(char *str, char ***dict, int ind, int suf_ind)
{
	int		cur_ind;
	char	*first;
	char	*second;
	char	*phrase;

	first = NULL;
	second = NULL;
	cur_ind = ind - 2;
	if (cur_ind > -1)
		first = get_hundreds(cur_ind, str, dict);
	cur_ind = ind - 1;
	if (cur_ind > -1)
		second = get_tens(cur_ind, str, dict, ind);
	if (second == NULL)
		second = get_singles(ind, str, dict);
	if (ind - 2 < 0 && suf_ind == 0)
		phrase = set_phrase(first, second, -1, dict);
	else
		phrase = set_phrase(first, second, suf_ind, dict);
	if (ind - 3 >= 0)
		show_numb(str, dict, ind - 3, suf_ind + 1);
	write_and_free(phrase, suf_ind);
}
