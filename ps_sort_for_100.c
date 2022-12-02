/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/02 16:56:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_smallest(int smallest, int content)
{
	if (smallest == content)
		return (1);
	else
		return (0);
}
t_dlist	*get_smallest(t_data *data)
{
	t_dlist	*a;

	data->chunk.small = data->a;
	a = data->a->next;
	while (a->next != NULL)
	{
		if (a->content < data->chunk.small->content)
			data->chunk.small = a;
		a = a->next;
	}
	if (a->content < data->chunk.small->content)
			data->chunk.small = a;
	return (data->chunk.small);
}

int	ft_100_find_position(t_data *data)
{
	t_dlist	*a;
	int		b;
	t_dlist	*smallest;

	a = data->a;
	b = data->b->content;
	smallest = get_smallest(data);
	while (a->next != NULL)
	{
		if ((b > a->content && b < a->next->content))
			return (a->index + 1);
		a = a->next;
	}
	a = data->a;
	while (a->next != NULL)
	{
		if (b > a->content && check_if_smallest(smallest->content, a->next->content))
			return (a->index + 1);
		a = a->next;
	}
	if (a->index + 1 == lst_len(data->a) && b < data->a->content)
	{
		if (b > a->content)
			return (FIRST);
		else
			return (MIDDLE);
	}
	return (-1);
}

void	sort_for_100(t_data *data)
{
	int	position;

	data->chunk.counter = data->total_int;
	label_order(data);
	push_to_b(data);
	sort_for_3(data);
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
