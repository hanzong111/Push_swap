/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:39:11 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/04 23:17:43 by ojing-ha         ###   ########.fr       */
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
	t_dlist	*b;
	int		content;

	if (src == NULL)
		return (0);
	a = *src;
	b = *des;
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
