/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:39:11 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/08 02:07:35 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_swap_list(t_dlist *list)
{
	int	a;
	int	b;

	if (list == NULL || list->next == NULL)
		return (0);
	a = list->content;
	list = list->next;
	b = list->content;
	list->content = a;
	list = list->previous;
	list->content = b;
	return (1);
}

int	ft_push_list(t_dlist **src, t_dlist **des)
{
	t_dlist	*a;
	int		content;

	if (src == NULL)
		return (0);
	a = *src;
	content = a->content;
	ft_del_front(src);
	ft_dlstadd_front(des, ft_dlstnew(content));
	return (1);
}

int	ft_rotate_list(t_dlist **lst)
{
	t_dlist	*current;
	int		content;

	current = *lst;
	if (current == NULL)
		return (0);
	content = current->content;
	ft_dlstadd_back(lst, ft_dlstnew(content));
	ft_del_front(lst);
	return (1);
}

int	ft_re_rotate_list(t_dlist **lst)
{
	t_dlist	*current;
	int		content;

	current = *lst;
	if (current == NULL)
		return (0);
	while (current)
	{
		if (current->next == NULL)
			break ;
		current = current->next;
	}
	content = current->content;
	ft_dlstadd_front(lst, ft_dlstnew(content));
	ft_del_back(lst);
	return (1);
}

void	ft_rrr(t_data *data)
{
	int	a;
	int	b;

	a = ft_re_rotate_list(&data->a);
	b = ft_re_rotate_list(&data->b);
	if (a || b)
		ft_printf("rrr\n");
}