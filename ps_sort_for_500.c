/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_500.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/03 16:12:10 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_chunck_500(t_data *data, int index)
{
	data->chunk.start = index * 40;
	if ((data->chunk.counter - 40) >= 0)
		data->chunk.end = data->chunk.start + 39;
	else
		data->chunk.end = data->total_int - 1;
	data->chunk.counter = data->chunk.counter - 40;
}

void	push_to_b_500(t_data *data)
{
	while ((data->chunk.counter - 40) >= -39)
	{
		static int	index;
		int			i;

		find_chunck_500(data, index);
		i = 0;
		while (++i <= 40 && data->a != NULL && lst_len(data->a) > 2)
		{
			find_hold_1_2(data);
			compare_steps(data);
		}
		index++;
	}
	ft_pa(data);
}

void	sort_for_500(t_data *data)
{
	data->chunk.counter = data->total_int;
	label_order(data);
	push_to_b_500(data);
	sort_for_3(data);
	insertion_sort(data);
}