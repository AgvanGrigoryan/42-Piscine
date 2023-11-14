/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:24:29 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/14 21:24:35 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_list.h"

/*void	read_data(t_list *list_item)
{
	char *data_ptr = (char *)(list_item->data);
	while (*data_ptr)
		printf("%c", *data_ptr++);
	printf("\n");
}*/
t_list	*ft_create_elem(void *data)
{
	t_list	*list_elem;

	list_elem = (t_list *)malloc(sizeof(t_list));
	if (list_elem == NULL)
		return (NULL);
	list_elem->next = NULL;
	list_elem->data = data;
	return (list_elem);
}
/*
int main(void)
{
	t_list list_item1;
	list_item1.data = malloc(sizeof(char) * 10);
	char *item2_data = "agvan gr";
	list_item1.next = ft_create_elem((void *)item2_data);
	read_data(list_item1.next);
}*/
