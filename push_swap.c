/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/04 18:42:46 by ojing-ha         ###   ########.fr       */
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
	printf("Start of my list\n");
	while (data.a->next != NULL)
	{
		printf("%d\n", data.a->content);
		data.a = data.a->next;
	}
	printf("%d\n", data.a->content);
	printf("End of my list\n");
	while (data.a->previous != NULL)
	{
		printf("%d\n", data.a->content);
		data.a = data.a->previous;
	}
	printf("%d\n", data.a->content);
	printf("Start of my list\n");
	printf("OK\n");
	return (0);
}
