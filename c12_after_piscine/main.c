/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:54:35 by aggrigor          #+#    #+#             */
/*   Updated: 2023/11/18 16:12:00 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

char	*ft_strdup(char *src); // ex00
void	print_list_data(t_list *list_item); // ex00
void	ft_list_push_front(t_list **begin_list,
			void *data); // ex01
int		ft_list_size(t_list *begin_list); // ex02
t_list	*ft_list_last(t_list *begin_list); // ex03
void	ft_list_push_back(t_list **begin_list,
			void *data); // ex04
t_list	*ft_list_push_strs(int size,
			char **strs); // ex05
void	ft_list_clear(t_list *begin_list,
			void (*free_fct)(void *)); // ex06
t_list	*ft_list_at(t_list *begin_list,
			unsigned int nbr); // ex07
void ft_list_reverse(t_list **begin_list); // ex08
void ft_list_foreach(t_list *begin_list,
			void (*f)(void *)); // ex09
void	ft_list_foreach_if(t_list *begin_list,
			void (*f)(void *), void *data_ref, int (*cmp)()); // ex10
t_list *ft_list_find(t_list *begin_list,
			void *data_ref, int (*cmp)()); // ex11
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *)); //ex12
void ft_list_merge(t_list **begin_list1,
			t_list *begin_list2); // ex13
void	ft_list_sort(t_list **begin_list,
			int (*cmp)()); // ex14
void	ft_list_reverse_fun(t_list *begin_list); // ex15
void	ft_sorted_list_insert(t_list **begin_list,
			void *data, int (*cmp)()); // ex16
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)()); // ex17

void	foo(void *ptr)
{
	printf("%s\n", (char *)ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned int)*s1 - (unsigned int)*s2);
}
t_list *create_list1(char ***data)
{
	t_list	*begin_list;
	int items_size;
	char **items_data;

	items_size = 5;
	items_data = malloc(sizeof(char *) * (items_size + 1));
	if (!items_data)
	{
		printf("NOT ALLOCATED, line:%d", __LINE__ - 3);
		return (0);
	}
	items_data[0] = ft_strdup("N");
	items_data[1] = ft_strdup("M");
	items_data[2] = ft_strdup("G");
	items_data[3] = ft_strdup("D");
	items_data[4] = ft_strdup("C");
	items_data[5] = NULL;
	begin_list = ft_list_push_strs(items_size, items_data);
	*data = items_data;
	return (begin_list);
}
t_list *create_list2(char ***data)
{
	t_list	*begin_list;
	int items_size;
	char **items_data;

	items_size = 4;
	items_data = malloc(sizeof(char *) * (items_size + 1));
	if (!items_data)
	{
		printf("NOT ALLOCATED, line:%d", __LINE__ - 3);
		return (0);
	}
	items_data[0] = ft_strdup("Q");
	items_data[1] = ft_strdup("P");
	items_data[2] = ft_strdup("F");
	items_data[3] = ft_strdup("B");
	items_data[4] = NULL;
	begin_list = ft_list_push_strs(items_size, items_data);
	*data = items_data;
	return (begin_list);
}
int	main(void)
{
	char **begin_list_data;
	char **second_list_data;
	t_list	*begin_list;
	t_list	*second_list;


	begin_list = create_list1(&begin_list_data);
	second_list = create_list2(&second_list_data);
	print_list_data(begin_list);
	printf("++++++++++++\n");
	print_list_data(second_list);
//	t_list *nth_item = ft_list_at(begin_list, 9);
//	if (nth_item == NULL)
//		printf("\nNUlL is returned\n");
//	else
//		printf("\nList address: %p,\nList->next: %p,\nList->data: %s\n", nth_item, nth_item->next, (char *)nth_item->data);
//	 printf("\nLIST SIZE=%d\n", ft_list_size(begin_list));
//	ft_list_reverse(&begin_list);
//	ft_list_foreach(begin_list, &foo);
//	ft_list_foreach_if(begin_list, &foo, (void *)items_data[2], &ft_strcmp);
//	print_list_data(ft_list_find(begin_list, (void *)items_data[4], &ft_strcmp));
//	ft_list_remove_if(&begin_list, (void *)items_data[3], &ft_strcmp, &free);
//	ft_list_merge(&begin_list, second_list);
//	char *inserting_item_data = ft_strdup("E");
//	ft_sorted_list_insert(&begin_list, inserting_item_data, &ft_strcmp);
//	ft_list_sort(&begin_list, &ft_strcmp);
//	ft_list_reverse_fun(begin_list);
	ft_sorted_list_merge(&begin_list, second_list, &ft_strcmp);
	print_list_data(begin_list);
//	ft_list_clear(begin_list, &free);
	return (0);
}
