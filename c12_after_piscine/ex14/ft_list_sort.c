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
#include <stdio.h> // delete
#include "ft_list.h"

void	print_list(t_list *list_item, int sorted) // delete
{
	if (sorted)
		printf("===SORTED===:\n");
	else
		printf("===LIST ITEMS===:\n");
	while (list_item)
	{
		printf("List address: %p, List->next: %p, ",
			   list_item, list_item->next);
		printf("List->data: '%s'\n", (char *) list_item->data);
		list_item = list_item->next;
	}
}
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

void	ft_merge_sorted_list(t_list **first_list, t_list *second_list,
			int (*cmp)())
{
	t_list	*first_list_ptr;
	t_list	*sorted_list;

	sorted_list = NULL;
	first_list_ptr = *first_list;
	while (first_list_ptr && second_list)
	{
		if ((*cmp)(first_list_ptr->data, second_list->data) < 0)
		{
			if (sorted_list)
			{
				sorted_list->next = first_list_ptr;
				sorted_list = sorted_list->next;
			}
			else
			{
				sorted_list = first_list_ptr;
				*first_list = sorted_list;
			}
			first_list_ptr = first_list_ptr->next;
		}
		else
		{
			if (sorted_list)
			{
				sorted_list->next = second_list;
				sorted_list = sorted_list->next;
			}
			else
			{
				sorted_list = second_list;
				*first_list = sorted_list;
			}
			second_list = second_list->next;
		}
	}
	if (first_list_ptr)
		sorted_list->next = first_list_ptr;
	else if(second_list)
		sorted_list->next = second_list;
}

void	ft_print_list_item(t_list *list_item)
{
	printf("List address: %p, List->next: %p, ",
		list_item, list_item->next);
	printf("List->data: '%s'\n", (char *) list_item->data);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*left;
	t_list	*right;
	t_list	*pre_right;
	int		list_size;

	list_size = ft_list_size(*begin_list);
	if (list_size < 2)
		return ;
	left = *begin_list;
	pre_right = ft_list_at(*begin_list, (list_size / 2) - 1);
	right = pre_right->next;
	pre_right->next = NULL;
//	print_list(left, 0);
//	print_list(right, 0);
//	printf("\n");
	ft_list_sort(&left, cmp);
	ft_list_sort(&right, cmp);
	ft_merge_sorted_list(&left, right, cmp);
	*begin_list = left;
//	print_list(right, 1);
}
