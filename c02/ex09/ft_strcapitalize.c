/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42yereva>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:42:44 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/18 22:23:24 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UPP_LOW_DIFF 32

int	is_alpha(char chr)
{
	if ('a' <= chr && chr <= 'z')
		return (1);
	else if ('A' <= chr && chr <= 'Z')
		return (2);
	else
		return (0);
}

int	is_numeric(char chr)
{
	return ('0' <= chr && chr <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int	is_frst_of_wrd;
	int	alpha;
	int	i;

	is_frst_of_wrd = 1;
	i = 0;
	while (str[i] != '\0')
	{
		alpha = is_alpha(str[i]);
		if (!(alpha > 0 || is_numeric(str[i])))
		{
			is_frst_of_wrd = 1;
			i++;
			continue ;
		}	
		if (is_frst_of_wrd && alpha == 1)
			str[i] -= UPP_LOW_DIFF;
		else if (!is_frst_of_wrd && alpha == 2)
			str[i] += UPP_LOW_DIFF;
		is_frst_of_wrd = 0;
		i++;
	}
	return (str);
}
