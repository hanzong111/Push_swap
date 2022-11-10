/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/10 18:44:56 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *data)
{
	if (data->total_int <= 3)
		sort_for_3(data);
	else if (data->total_int <= 5)
		sort_for_5(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_dlist	*a;
	t_dlist	*b;

	ps_initialize(&data);
	error_checks(argv, &data);
	if (argc > 1)
	{
		make_int_list(&data);
		if (data.total_int != 1)
			push_swap(&data);
	}
	a = data.a;
	b = data.b;
	// printf("Start of stack a\n");
	// if (data.a != NULL)
	// {
	// 	while (data.a->next != NULL)
	// 	{
	// 		printf("%d\n", data.a->content);
	// 		data.a = data.a->next;
	// 	}
	// 	printf("%d\n", data.a->content);
	// }
	// printf("End of stack a\n");
	// printf("Start of stack b\n");
	// if (data.b != NULL)
	// {
	// 	while (data.b->next != NULL)
	// 	{
	// 		printf("%d\n", data.b->content);
	// 		data.b = data.b->next;
	// 	}
	// 	printf("%d\n", data.b->content);
	// }
	// printf("End of stack b\n");
	// printf("OK\n");
	data.a = a;
	data.b = b;
	free_lst(&data);
	return (0);
}
