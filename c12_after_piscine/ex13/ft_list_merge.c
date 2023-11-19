/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:27:25 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/19 20:27:41 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list_ptr;

	if (!begin_list1 || !(*begin_list1)
		|| !begin_list2)
		return ;
	list_ptr = *begin_list1;
	while (list_ptr->next)
		list_ptr = list_ptr->next;
	list_ptr->next = begin_list2;
}
