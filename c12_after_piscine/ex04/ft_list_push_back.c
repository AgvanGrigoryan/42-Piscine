/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:49:19 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/15 10:49:23 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list_iter;

	list_iter = *begin_list;
	while (list_iter->next)
		list_iter = list_iter->next;
	list_iter->next = ft_create_elem(data);
}
