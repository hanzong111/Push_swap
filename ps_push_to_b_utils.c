/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_to_b_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/10 16:52:00 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	operations_100(data, h1_steps, h2_steps);
	ft_pb(data);
}
