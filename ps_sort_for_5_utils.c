/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_5_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/01 18:16:33 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_5_lst_len(t_dlist *a)
{
	int	i;

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
	t_dlist	*a;

	a = data->a;
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (1);
		else
			a = a->next;
	}
	return (0);
}

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

int	ft_check_insert(t_data *data)
{
	t_dlist	*a_last;
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
