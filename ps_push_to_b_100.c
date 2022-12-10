/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_to_b_100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/10 16:52:08 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_100(t_data *data, int h1_steps, int h2_steps)
{
	if (h1_steps < h2_steps)
	{
		if (data->hold._1 < lst_len(data->a) / 2)
			ft_repeat_op(data, ft_ra, h1_steps);
		else
			ft_repeat_op(data, ft_rra, h1_steps);
	}
	else if (h2_steps < h1_steps)
	{
		if (data->hold._2 < lst_len(data->a) / 2)
			ft_repeat_op(data, ft_ra, h2_steps);
		else
			ft_repeat_op(data, ft_rra, h2_steps);
	}
	else
	{
		if (data->hold._1 < data->hold._2)
			ft_repeat_op(data, ft_ra, h1_steps);
		else
			ft_repeat_op(data, ft_rra, h2_steps);
	}
}

void	push_to_b_100(t_data *data)
{
	static int	index;
	int			i;

	while ((data->chunk.counter - 20) >= -19)
	{
		find_chunck(data, index);
		i = 0;
		while (++i <= 20 && data->a != NULL && lst_len(data->a) > 2)
		{
			hold_1(data);
			hold_2(data);
			compare_steps(data);
		}
		index++;
	}
	ft_pa(data);
}
