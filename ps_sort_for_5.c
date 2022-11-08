/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/08 22:23:55 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <sys/types.h>
#include <sys/wait.h>


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

int	ft_check_ascending(t_data *data)
{
	int		a;
	t_dlist *next;

	a = data->a->content;
	next = data->a;
	next = next->next;
	while (next)
	{
		if (a > next->content)
			return (1);
		a = next->content;
		if (next->next != NULL)
		{
			a = next->content;
			next = next->next;
		}
		else
			break;
	}
	return (0);
}

int	ft_check_insert(t_data *data)
{
	t_dlist *a_last;
	int		b;

	a_last = data->a;
	b = data->b->content;
	while (a_last)
	{
		if (a_last->next == NULL)
			break ;
		a_last = a_last->next;
	}
	if (b > a_last->content)
		return (1);
	else
		return (0);
}

void	sort_for_5(t_data *data)
{
	int		position;
	int		b;

	while (ft_5_lst_len(data->a) != 3)
		ft_pb(data);
	sort_for_3(data);
	if (data->b->next != NULL)
	{
		b = data->b->next->content;
		if (data->b->content < b)
		ft_sb(data);
	}
	position = ft_5_find_position(data->a, data->b);
	ft_5_insertion_1(data, position);
	while (ft_check_ascending(data))
	{
		if (data->b != NULL && ft_check_insert(data))
			ft_pa(data);
		ft_rra(data);
	}
	if (data->b != NULL)
	{
		ft_5_insertion_1(data, ft_5_find_position(data->a, data->b));
		while (ft_check_ascending(data))
		ft_rra(data);
	}

}