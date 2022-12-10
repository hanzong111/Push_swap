/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/10 16:50:04 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_chunck(t_data *data, int index)
{
	data->chunk.start = index * 20;
	if ((data->chunk.counter - 20) >= 0)
		data->chunk.end = data->chunk.start + 19;
	else
		data->chunk.end = data->total_int - 1;
	data->chunk.counter = data->chunk.counter - 20;
}

void	hold_1(t_data *data)
{
	t_dlist	*start;

	start = data->a;
	while (start->next != NULL)
	{
		if (start->order >= data->chunk.start
			&& start->order <= data->chunk.end)
		{
			data->hold._1 = start->index;
			break ;
		}
		start = start->next;
	}
	if (start->order >= data->chunk.start && start->order <= data->chunk.end)
			data->hold._1 = start->index;
}

void	hold_2(t_data *data)
{
	t_dlist	*last;

	last = ft_move_down(data->a, lst_len(data->a) - 1);
	while (last->previous != NULL)
	{
		if (last->order >= data->chunk.start
			&& last->order <= data->chunk.end)
		{
			data->hold._2 = last->index;
			break ;
		}
		last = last->previous;
	}
	if (last->order >= data->chunk.start && last->order <= data->chunk.end)
			data->hold._2 = last->index;
}
