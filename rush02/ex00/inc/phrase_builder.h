/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phrase_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:04:12 by sosokin           #+#    #+#             */
/*   Updated: 2023/10/29 18:04:56 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHRASE_BUILDER_H
# define PHRASE_BUILDER_H

# include <stdlib.h>
# include "utils.h"

char	*create_phrase(char *first, char *second, char *sep);

char	*get_hundreds(int h_ind, char *str, char ***dict);

char	*get_tens(int t_ind, char *str, char ***dict, int ind);

char	*get_singles(int ind, char *str, char ***dict);

#endif
