/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:55:18 by sosokin           #+#    #+#             */
/*   Updated: 2023/10/29 22:18:19 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

int		ft_strlen(char *str);

char	*ft_strcat(char *dest, char *src);

void	write_phrase(char *phrase, int ind);

int		print_error(char *str);

void	free_dict(char ***dict);

#endif
