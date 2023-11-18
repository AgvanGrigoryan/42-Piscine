/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:00:23 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/18 16:00:32 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next_item;
	t_list	*prev_item;

	prev_item = NULL;
	while ((*begin_list))
	{
		next_item = (*begin_list)->next;
		(*begin_list)->next = prev_item;
		prev_item = (*begin_list);
		(*begin_list) = next_item;
	}
	(*begin_list) = prev_item;
}
