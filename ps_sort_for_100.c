/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/18 19:21:50 by ojing-ha         ###   ########.fr       */
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

void	sort_for_100(t_data *data)
{
	static int	index;

	data->chunk.counter = data->total_int;
	while ((data->chunk.counter - 20) >= -19)
	{
		find_chunck(data, index);
		// printf("Chunk[%d] Start is : %d\n", index,  data->chunk.start);
		// printf("Chunk[%d] End is : %d\n", index, data->chunk.end);
		index++;
	}
}
