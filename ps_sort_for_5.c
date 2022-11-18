/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/18 20:38:22 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_5_insertion_1(t_data *data, int position)
{
	if (position == 1)
		ft_pa(data);
	else if (position == 2)
	{
		ft_ra(data);
		ft_pa(data);
	}
	else if (position == 3)
	{
		ft_repeat_op(data, ft_ra, 2);
		ft_pa(data);
	}
	else if (position == 4)
	{
		ft_pa(data);
		ft_rra(data);
		ft_sa(data);
		ft_repeat_op(data, ft_ra, 2);
	}
	else if (position == LAST)
	{
		ft_pa(data);
		ft_ra(data);
	}
}

void	make_b_ascending(t_data *data)
{
	if (data->b->content < data->b->next->content)
		ft_sb(data);
}

void	insert_last_int(t_data *data)
{
	ft_5_insertion_1(data, ft_5_find_position(data->a, data->b));
	while (ft_check_ascending(data))
		ft_rra(data);
}

void	sort_for_5(t_data *data)
{
	int		position;

	while (ft_5_lst_len(data->a) != 3)
		ft_pb(data);
	sort_for_3(data);
	if (data->b->next != NULL)
		make_b_ascending(data);
	position = ft_5_find_position(data->a, data->b);
	ft_5_insertion_1(data, position);
	while (ft_check_ascending(data))
	{
		if (data->b != NULL && ft_check_insert(data))
			ft_pa(data);
		ft_rra(data);
	}
	if (data->b != NULL)
		insert_last_int(data);
}
