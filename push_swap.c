/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/01/12 20:09:39 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *data)
{
	if (lst_len(data->a) == 2)
	{
		if (data->a->content > data->a->next->content)
			ft_sa(data);
		return ;
	}
	else if (data->total_int <= 3)
		sort_for_3(data);
	else if (data->total_int <= 5)
		sort_for_5(data);
	else if (data->total_int <= 100)
		sort_for_100(data);
	else
		sort_for_500(data);
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
	free_lst(&data);
	return (0);
}
