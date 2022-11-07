/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/08 03:29:53 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_5_find_position(t_dlist *a, t_dlist *b)
{
	int	position;

	position = 1;
	while (b->content > a->content && a->next != NULL)
	{
		position++;
		a = a->next;
	}
	if (a->next == NULL && b->content > a->content)
		position = LAST;
	return (position);
}

void	ft_5_insertion(t_data *data)
{
	if (ft_5_find_position(data->a, data->b) == 1)
		ft_pa(data);
	else if (ft_5_find_position(data->a, data->b) == 2)
	{
		ft_ra(data);
		ft_pa(data);
		ft_rra(data);
	}
	else if (ft_5_find_position(data->a, data->b) == 3)
	{
		ft_repeat_op(data, ft_ra, 2);
		ft_pa(data);
		ft_repeat_op(data, ft_rra, 2);
	}
	else if (ft_5_find_position(data->a, data->b) == 4)
	{
		ft_pa(data);
		ft_rra(data);
		ft_sa(data);
		ft_repeat_op(data, ft_ra, 2);
	}
	else if (ft_5_find_position(data->a, data->b) == LAST)
	{
		ft_pa(data);
		ft_ra(data);
	}
}

int	ft_5_lst_len(t_dlist *a)
{
	int i;

	i = 0;
	while (a && a->next != NULL)
	{
		a = a->next;
		i++;
	}
	i++;
	return (i);
}

void	sort_for_5(t_data *data)
{
	ft_pb(data);
	if (ft_5_lst_len(data->a) != 3)
		ft_pb(data);
	sort_for_3(data);
	ft_5_insertion(data);
	if (data->b != NULL)
		ft_5_insertion(data);
}