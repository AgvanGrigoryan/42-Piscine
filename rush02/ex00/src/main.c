/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:33:20 by aggrigor          #+#    #+#             */
/*   Updated: 2023/10/29 23:33:55 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/validate_dict.h"
#include "../inc/validate.h"
#include "../inc/printer.h"
#include "../inc/utils.h"

int	main(int argc, char *argv[])
{
	int				fdict;
	unsigned int	nb_len;
	unsigned int	max_len;
	char			***dict;
	char			*dict_path;

	if (argc == 2)
		dict_path = "./numbers.dict";
	else if (argc == 3)
		dict_path = argv[2];
	else
		return (print_error("Error\n"));
	fdict = open(dict_path, O_RDONLY);
	if (fdict == -1)
		return (print_error("Dict Error\n"));
	dict = check_dict(fdict, &max_len);
	close(fdict);
	if (dict == NULL)
		return (print_error("Dict Error\n"));
	nb_len = validate_nb(&argv[1], max_len + 2);
	if (nb_len == 0)
		return (print_error("Error\n"));
	show_numb(argv[1], dict, nb_len - 1, 0);
	free_dict(dict);
	return (0);
}
