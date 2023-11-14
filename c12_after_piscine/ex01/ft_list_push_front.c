/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:00:08 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/14 22:00:28 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

//char	*ft_strdup(char *src);
//void	print_list_data(t_list *list_item);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	list = ft_create_elem(data);
	list->next = *begin_list;
	*begin_list = list;
}

//int	main(void)
//{
//	t_list	*list_item1;
//	char	item1_data[] = "INIT-FIRST";
//	list_item1->data = (void *) ft_strdup(item1_data);
//	list_item1->next = NULL;
//	char	item2_data[] = "FIRST-PUSHED";
//	ft_list_push_front(&list_item1, (void *)ft_strdup(item2_data));
//	char	item3_data[] = "SECOND-PUSHED";
//	ft_list_push_front(&list_item1, (void *) ft_strdup(item3_data));
//	printf("LIST ITEMS:\n");
//	print_list_data(list_item1);
//	return (0);
//}
