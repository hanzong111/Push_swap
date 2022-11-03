/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:38:54 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/03 18:43:05 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_duplicate(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->total_int)
	{
		j = 1;
		while ((i - j) >= 0)
		{
			if (data->i[i] == data->i[i - j])
			{
				write(2, "Error\n", 6);
				free(data->i);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	error_checks(char **argv, t_data *data)
{
	check_char(argv);
	integer_count(argv, data);
	make_int_array(argv, data);
	check_duplicate(data);
}
