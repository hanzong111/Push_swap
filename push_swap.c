/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/30 20:51:27 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *data)
{
	if (data->total_int <= 3)
		sort_for_3(data);
	else if (data->total_int <= 5)
		sort_for_5(data);
	else if (data->total_int <= 100)
		sort_for_100(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ps_initialize(&data);
	error_checks(argv, &data);
	if (argc > 1)
	{
		make_int_list(&data);
		if (data.total_int != 1)
			push_swap(&data);
	}
	// print_stack(&data);
	free_lst(&data);
	return (0);
}
