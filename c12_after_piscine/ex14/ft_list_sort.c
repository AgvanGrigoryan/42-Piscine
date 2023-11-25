/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:35:54 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/20 10:36:18 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr && begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	if (i != nbr)
		return (NULL);
	return (begin_list);
}

t_list	*ft_merge_sorted_list(t_list *left, t_list *right,
			int (*cmp)())
{
	t_list	dummy;
	t_list	*sorted_list;

	sorted_list = &dummy;
	while (left && right)
	{
		if ((*cmp)(left->data, right->data) < 0)
		{
			sorted_list->next = left;
			left = left->next;
		}
		else
		{
			sorted_list->next = right;
			right = right->next;
		}
		sorted_list = sorted_list->next;
	}
	if (left)
		sorted_list->next = left;
	else if (right)
		sorted_list->next = right;
	return (dummy.next);
}

t_list	*merge_sort(t_list *begin_list, int (*cmp)())
{
	t_list	*left;
	t_list	*right;
	t_list	*pre_right;
	int		list_size;

	list_size = ft_list_size(begin_list);
	if (begin_list == NULL || list_size < 2)
		return (begin_list);
	left = begin_list;
	pre_right = ft_list_at(begin_list, (list_size / 2) - 1);
	right = pre_right->next;
	pre_right->next = NULL;
	left = merge_sort(left, cmp);
	right = merge_sort(right, cmp);
	return (ft_merge_sorted_list(left, right, cmp));
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	*begin_list = merge_sort(*begin_list, cmp);
}
