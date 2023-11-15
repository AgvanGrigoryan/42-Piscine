/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:03:10 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/15 16:03:12 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*new_list;
	t_list	*next_item_addr;

	next_item_addr = NULL;
	i = 0;
	while (i < size)
	{
		new_list = ft_create_elem(strs[i]);
		new_list->next = next_item_addr;
		next_item_addr = new_list;
		i++;
	}
	return (new_list);
}
