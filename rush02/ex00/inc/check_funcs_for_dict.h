/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs_for_dict.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:27:25 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/29 20:35:47 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECK_FUNCS_FOR_DICT_H
# define CHECK_FUNCS_FOR_DICT_H

int		is_printable(char chr);
int		is_numeric(char chr);
int		is_space(char chr);
char	*ft_strncpy(char *dest, char *src, int len);
int		check_format(char *buf, int *i, unsigned int *num_len, char **start);

#endif
