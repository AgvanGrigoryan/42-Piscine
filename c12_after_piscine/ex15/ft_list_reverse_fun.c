/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:35:29 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/26 14:35:43 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdio.h>

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	void	*tmp;
	int		i;
	int		j;
	int		n;

	current = begin_list;
	while (current && ++n)
		current = current->next;
	printf("\n================================%d\n", n);
	i = 0;
	while (i < n - 1)
	{
		j = i;
		current = begin_list;
		while (current && current->next && j < n - 1)
		{
			tmp = current->data;
			current->data = current->next->data;
			current->next->data = tmp;
			current = current->next;
			j++;
		}
		i++;
	}
}
