/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_d_list_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:45:43 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/21 21:01:01 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_dlist	*ft_move_down(t_dlist *lst, int i)
{
	while (--i >= 0)
		lst = lst->next;
	return (lst);
}

void	ft_repeat_op(t_data *data, void (*op)(t_data *), int repeat)
{
	while (--repeat >= 0)
		(*op)(data);
}

void	ft_repeat_lst(t_dlist **lst, void (*op)(t_dlist **), int repeat)
{
	while (--repeat >= 0)
		(*op)(lst);
}

void	free_lst(t_data *data)
{
	t_dlist	*next;

	next = data->a;
	while (next)
	{
		next = next->next;
		free(data->a);
		data->a = next;
	}
	data->a = NULL;
	next = data->b;
	while (next)
	{
		next = next->next;
		free(data->b);
		data->b = next;
	}
	data->b = NULL;
}

void	correct_index(t_dlist *lst, int start)
{
	if (lst == NULL)
		return ;
	lst->index = start;
	while (lst->next != NULL)
	{
		lst = lst->next;
		lst->index = start + 1;
		start++;
	}
	lst->index = start;
}
