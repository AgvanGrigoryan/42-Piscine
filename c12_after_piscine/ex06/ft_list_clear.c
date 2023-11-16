/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:33:27 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/16 09:34:03 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next_item;

	while (begin_list)
	{
		next_item = begin_list->next;
		(*free_fct)(begin_list);
		begin_list = next_item;
	}
}
