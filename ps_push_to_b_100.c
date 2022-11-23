/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_to_b_100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/22 21:12:30 by ojing-ha         ###   ########.fr       */
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

void	find_hold_1_2(t_data *data)
{
	t_dlist	*start;
	t_dlist	*last;

	start = data->a;
	last = ft_move_down(data->a, lst_len(data->a) - 1);
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
}

int	lst_len(t_dlist *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	calculate_steps(t_data *data, int hold)
{
	if (hold < lst_len(data->a) / 2)
		return (hold);
	else if (hold > lst_len(data->a) / 2)
		return (lst_len(data->a) - hold);
	return (hold);
}

void	compare_steps(t_data *data)
{
	int	h1_steps;
	int	h2_steps;

	h1_steps = calculate_steps(data, data->hold._1);
	h2_steps = calculate_steps(data, data->hold._2);
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
	ft_pb(data);
}

void	push_to_b(t_data *data)
{
	while ((data->chunk.counter - 20) >= -19)
	{
		static int	index;
		int			i;

		find_chunck(data, index);
		i = 0;
		while (++i <= 20 && data->a != NULL)
		{
			find_hold_1_2(data);
			compare_steps(data);
		}
		index++;
	}
	ft_pa(data);
}