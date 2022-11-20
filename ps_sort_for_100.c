/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/20 19:38:56 by ojing-ha         ###   ########.fr       */
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
	printf("Chunk start is %d\n", data->chunk.start);
	printf("Chunk end is %d\n", data->chunk.end);
}

void	find_hold_1_2(t_data *data)
{
	t_dlist	*start;
	t_dlist	*last;

	start = data->a;
	last = ft_move_down(data->a, data->total_int - 1);
	printf("last previous is %d\n", last->previous->content);
	while (start->next != NULL)
	{
		if (start->order >= data->chunk.start
			&& start->order <= data->chunk.end)
		{
			data->hold._1 = start->index;
			break;
		}
		start = start->next;
	}
	if (start->order >= data->chunk.start
			&& start->order <= data->chunk.end)
			data->hold._1 = start->index;
	printf("Hold 1 is %d\n", data->hold._1);
	while (last->previous != NULL)
	{
		if (last->order >= data->chunk.start
			&& last->order <= data->chunk.end)
		{
			data->hold._2 = last->index;
			break;
		}
		last = last->previous;
	}
	if (last->order >= data->chunk.start
			&& last->order <= data->chunk.end)
			data->hold._2 = last->index;
	printf("Hold 2 is %d\n", data->hold._2);
}

void	sort_for_100(t_data *data)
{
	static int	index;
	// int			i;

	data->chunk.counter = data->total_int;
	label_order(data);
	// while ((data->chunk.counter - 20) >= -19)
	// {
		find_chunck(data, index);
		// i = 0;
		// while (++i <= 20 && data->a != NULL)
		// {
			find_hold_1_2(data);
			// compare_steps(data);
			// op_execute(data);
		// }
		index++;
	// }
}
