/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_int_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:33:57 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/18 20:04:57 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	assign_index(t_data *data)
{
	int		index;
	t_dlist	*start;

	index = 0;
	start = data->a;
	while (index < data->total_int)
	{
		data->a->index = index;
		data->a = data->a->next;
		index++;
	}
	data->a = start;
}

// void	print(t_data *data)
// {
// 	t_dlist	*start;

// 	start = data->a;
// 	while (data->a != NULL)
// 	{
// 		printf("%d\n", data->a->index);
// 		data->a = data->a->next;
// 	}
// 	data->a = start;
// }

void	make_int_list(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->total_int)
	{
		ft_dlstadd_back(&data->a, ft_dlstnew(data->i[index]));
		index++;
	}
	free(data->i);
	assign_index(data);
	// print(data);
}
