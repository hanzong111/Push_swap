/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/03 16:05:49 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_data *data)
{
	int	position;
	
	while (lst_len(data->b) > 0)
	{
		position = ft_100_find_position(data);
		if (position == FIRST)
			ft_pa(data);
		else if (position == MIDDLE)
		{
			if (data->chunk.small->index < lst_len(data->a) / 2)
				ft_repeat_op(data, ft_ra, data->chunk.small->index);
			else
				ft_repeat_op(data, ft_rra, lst_len(data->a) - data->chunk.small->index);
			ft_pa(data);
		}
		else
		{
			if (position < lst_len(data->a) / 2)
				ft_repeat_op(data, ft_ra, position);
			else
				ft_repeat_op(data, ft_rra, lst_len(data->a) - position);
			ft_pa(data);
		}
	}
	get_smallest(data);
	if (data->chunk.small->index < lst_len(data->a) / 2)
		ft_repeat_op(data, ft_ra, data->chunk.small->index);
	else
		ft_repeat_op(data, ft_rra, lst_len(data->a) - data->chunk.small->index);
}