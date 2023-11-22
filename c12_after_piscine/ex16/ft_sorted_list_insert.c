/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:02:18 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/21 19:02:33 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current_item;
	t_list	*prev_item;
	t_list	*new_item;

	current_item = *begin_list;
	prev_item = NULL;
	new_item = ft_create_elem(data);
	if (new_item == NULL)
		return ;
	else if (current_item == NULL)
	{
		*begin_list = new_item;
		return ;
	}
	while (current_item && (*cmp)(current_item->data, new_item->data) < 0)
	{
		prev_item = current_item;
		current_item = current_item->next;
	}
	new_item->next = current_item;
	if (prev_item)
		prev_item->next = new_item;
	else
		*begin_list = new_item;
}
