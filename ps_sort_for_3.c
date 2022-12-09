/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:59:24 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/09 22:00:06 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3_compare(int a, int b, int c)
{
	if ((a > b) && (a < c) && (b < c))
		return (1);
	else if ((a > b) && (a > c) && (b > c))
		return (2);
	else if ((a > b) && (a > c) && (b < c))
		return (3);
	else if ((a < b) && (a < c) && (b > c))
		return (4);
	else if ((a < b) && (a > c) && (b > c))
		return (5);
	return (0);
}

void	sort_for_3(t_data *data)
{
	t_dlist	*_1;
	t_dlist	*_2;
	t_dlist	*_3;

	_1 = data->a;
	_2 = ft_move_down(data->a, 1);
	_3 = ft_move_down(data->a, 2);
	if (sort_3_compare(_1->content, _2->content, _3->content) == 1)
		ft_sa(data);
	else if (sort_3_compare(_1->content, _2->content, _3->content) == 2)
	{
		ft_sa(data);
		ft_rra(data);
	}
	else if (sort_3_compare(_1->content, _2->content, _3->content) == 3)
		ft_ra(data);
	else if (sort_3_compare(_1->content, _2->content, _3->content) == 4)
	{
		ft_sa(data);
		ft_ra(data);
	}
	else if (sort_3_compare(_1->content, _2->content, _3->content) == 5)
		ft_rra(data);
}
