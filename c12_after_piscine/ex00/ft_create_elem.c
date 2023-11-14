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
#include <stdio.h>
#include "ft_list.h"

/*int	ft_strlen(char *src)
{
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}*/

/*void	ft_strncpy(char *dst, char *src, unsigned int src_l)
{
	unsigned int	i;

	i = 0;
	while (i < src_l && *src)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}*/

/*char	*ft_strdup(char *src)
{
	char			*mem;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	mem = (char *)malloc(sizeof(char) * src_len + 1);
	if (mem == NULL)
		return (NULL);
	ft_strncpy(mem, src, src_len);
	return (mem);
}*/

/*void	print_list_data(t_list *list_item)
{
	char	*data_ptr;

	while (list_item)
	{
		printf("List address: %p,\nList->next: %p,\n",
			list_item, list_item->next);
		data_ptr = (char *) list_item->data;
		printf("List->data: '%s'\n\n", data_ptr);
		list_item = list_item->next;
	}
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
/*int main(void)
{
	t_list *list_item1;
	char *item1_data = ft_strdup("FIRST ITEM DATA");
	list_item1 = ft_create_elem((void *)item1_data);
	print_list_data(list_item1);
}*/
