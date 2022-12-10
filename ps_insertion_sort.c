/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/10 16:47:48 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_100_find_position_1(t_data *data)
{
	t_dlist	*a;
	int		b;

	a = data->a;
	b = data->b->content;
	while (a->next != NULL)
	{
		if ((b > a->content && b < a->next->content))
			return (a->index + 1);
		a = a->next;
	}
	return (-1);
}

int	ft_100_find_position_2(t_data *data)
{
	t_dlist	*a;
	t_dlist	*smallest;
	int		b;

	a = data->a;
	b = data->b->content;
	smallest = get_smallest(data);
	while (a->next != NULL)
	{
		if (b > a->content && check_if_smallest(smallest->content,
				a->next->content))
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

void	ft_operations_100(t_data *data, int position)
{
	if (position == FIRST)
		ft_pa(data);
	else if (position == MIDDLE)
	{
		if (data->chunk.small->index < lst_len(data->a) / 2)
			ft_repeat_op(data, ft_ra, data->chunk.small->index);
		else
			ft_repeat_op(data, ft_rra,
				lst_len(data->a) - data->chunk.small->index);
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

void	get_correct_position(t_data *data)
{
	int	position;

	while (lst_len(data->b) > 0)
	{
		position = ft_100_find_position_1(data);
		if (position < 0)
			position = ft_100_find_position_2(data);
		ft_operations_100(data, position);
	}
}

void	insertion_sort(t_data *data)
{
	get_correct_position(data);
	get_smallest(data);
	if (data->chunk.small->index < lst_len(data->a) / 2)
		ft_repeat_op(data, ft_ra, data->chunk.small->index);
	else
		ft_repeat_op(data, ft_rra, lst_len(data->a) - data->chunk.small->index);
}
