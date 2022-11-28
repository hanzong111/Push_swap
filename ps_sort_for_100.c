/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/24 18:30:20 by ojing-ha         ###   ########.fr       */
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
int	get_smallest(t_data *data)
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
	return (data->chunk.small->content);
}

int	ft_100_find_position(t_data *data)
{
	t_dlist	*a;
	int		b;
	int		smallest;

	a = data->a;
	b = data->b->content;
	smallest = get_smallest(data);
	printf("smallest is %d\n", smallest);
	while (a->next != NULL)
	{
		if (b > a->content && b < a->next->content)
			return (a->index + 1);
		a = a->next;
	}
	a = data->a;
	while (a->next != NULL)
	{
		if ((b > a->content && check_if_smallest(smallest, a->next->content))
				||(b < a->content && check_if_smallest(smallest, a->next->content)))
			return (a->index + 1);
		a = a->next;
	}
	printf("lst len is %d\n", lst_len(data->a));
	if (a->index + 1 == lst_len(data->a))
		return (-2);
	return (-1);
}

void	sort_for_100(t_data *data)
{
	int	position;

	data->chunk.counter = data->total_int;
	label_order(data);
	push_to_b(data);
	sort_for_5(data);
	while (lst_len(data->b) > 0)
	{
		position = ft_100_find_position(data);
		printf("position is %d\n", position);
		if (position == -2)
		{
			ft_pa(data);
			ft_ra(data);
		}
		else
		{
			ft_repeat_op(data, ft_ra, position);
			ft_pa(data);
		}
	}
	// ft_repeat_op(data, ft_rra, 16);
}
