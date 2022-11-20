/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_label_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/20 17:34:23 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_small_big(t_data *data)
{
	t_dlist	*a;

	data->chunk.small = data->a;
	data->chunk.big = data->a;
	a = data->a->next;
	while (a->next != NULL)
	{
		if (a->content < data->chunk.small->content)
			data->chunk.small = a;
		if (a->content > data->chunk.big->content)
			data->chunk.big = a;
		a = a->next;
	}
	if (a->content < data->chunk.small->content)
			data->chunk.small = a;
	if (a->content > data->chunk.big->content)
			data->chunk.big = a;
	data->chunk.index = data->chunk.small->index;
	data->chunk.temp = data->chunk.small->content;
}

void	get_int_position(t_data *data)
{
	t_dlist	*a;

	data->chunk.current = data->chunk.big;
	a = data->a;
	while (a->next != NULL)
	{
		if (a->content < data->chunk.current->content
			&& a->content > data->chunk.temp)
			data->chunk.current = a;
		a = a->next;
	}
	if (a->content < data->chunk.current->content
		&& a->content > data->chunk.temp)
		data->chunk.current = a;
	data->chunk.index = data->chunk.current->index;
}

void	write_order(t_data *data, int order)
{
	t_dlist	*a;

	a = ft_move_down(data->a, data->chunk.index);
	a->order = order;
	data->chunk.temp = a->content;
}

void	label_order(t_data *data)
{
	int	order;

	order = 0;
	get_small_big(data);
	write_order(data, order);
	order++;
	while (data->chunk.temp != data->chunk.big->content)
	{
		get_int_position(data);
		write_order(data, order);
		order++;
	}
}
