/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/05 15:05:50 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ps_initialize(&data);
	if (argc != 1)
	{
		error_checks(argv, &data);
		make_int_list(&data);
	}
	ft_pb(&data);
	ft_pb(&data);
	ft_pb(&data);
	ft_rra(&data);
	ft_rrb(&data);
	ft_rrr(&data);
	printf("Start of stack a\n");
	if (data.a != NULL)
	{
		while (data.a->next != NULL)
		{
			printf("%d\n", data.a->content);
			data.a = data.a->next;
		}
		printf("%d\n", data.a->content);
	}
	printf("End of stack a\n");
	printf("Start of stack b\n");
	if (data.b != NULL)
	{
		while (data.b->next != NULL)
		{
			printf("%d\n", data.b->content);
			data.b = data.b->next;
		}
		printf("%d\n", data.b->content);
	}
	printf("End of stack b\n");
	printf("OK\n");
	system("leaks push_swap");
	return (0);
}
