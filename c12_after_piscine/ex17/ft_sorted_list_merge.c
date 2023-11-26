/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:32:14 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/26 19:33:09 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	t_list	dummy;
	t_list	*sorted_list;

	sorted_list = &dummy;
	while ((*begin_list1) && begin_list2)
	{
		if ((*cmp)((*begin_list1)->data, begin_list2->data) < 0)
		{
			sorted_list->next = (*begin_list1);
			(*begin_list1) = (*begin_list1)->next;
		}
		else
		{
			sorted_list->next = begin_list2;
			begin_list2 = begin_list2->next;
		}
		sorted_list = sorted_list->next;
	}
	if ((*begin_list1))
		sorted_list->next = (*begin_list1);
	else if (begin_list2)
		sorted_list->next = begin_list2;
	*begin_list1 = dummy.next;
}
