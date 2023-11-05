/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:24:07 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/29 20:36:10 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_DICT_H
# define VALIDATE_DICT_H

char	***check_dict(int descr, unsigned int *max_len);
int		parse_dict(char ***dict, char *buf, unsigned int *max_len);

#endif
