/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/22 21:17:08 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_100_find_position(t_dlist *a, t_dlist *b)
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

void	sort_for_100(t_data *data)
{
	data->chunk.counter = data->total_int;
	label_order(data);
	push_to_b(data); 
}
