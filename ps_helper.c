/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:24:43 by plau              #+#    #+#             */
/*   Updated: 2022/11/18 20:19:59 by ojing-ha         ###   ########.fr       */
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

int	*lst_to_arry(t_dlist *lst)
{
	int len;
	int index;
	int	*arry;

	len = lst_len(lst);
	index = 0;
	arry = malloc(sizeof(int) * len);
	while (index < len)
	{
		arry[index] = lst->content;
		index++;
		lst = lst->next;
	}
	return (arry);
}

int	*lst_to_index(t_dlist *lst)
{
	int len;
	int index;
	int	*arry;

	len = lst_len(lst);
	index = 0;
	arry = malloc(sizeof(int) * len);
	while (index < len)
	{
		arry[index] = lst->index;
		index++;
		lst = lst->next;
	}
	return (arry);
}

void	print_stack(t_data *data)
{
	int	index;
	int	*a;
	int	*b;
	int	*i;

	index = 0;
	a = lst_to_arry(data->a);
	b = lst_to_arry(data->b);
	i = lst_to_index(data->a);
	printf("\nIndex\t|    Stack A\t|    Stack B\n");
	printf("--------|---------------|---------------\n");
	while (index < lst_len(data->a))
	{
		printf("   %d\t|\t%d\t|", i[index], a[index]);
		if (index < lst_len(data->b))
			printf("\t%d", b[index]);
		printf("\n");
		index++;
	}
	printf("\n");
	free(a);
	free(b);
	free(i);
}