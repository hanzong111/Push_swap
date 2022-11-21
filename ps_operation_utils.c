/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:39:11 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/21 20:17:46 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_swap_list(t_dlist **list)
{
	t_dlist	*lst;
	t_dlist	*a;
	t_dlist	*b;

	lst = *list;
	if (lst == NULL || lst->next == NULL)
		return (0);
	a = ft_dlstnew(lst->content, lst->order);
	lst = lst->next;
	b = ft_dlstnew(lst->content, lst->order);
	lst = lst->previous;
	ft_repeat_lst(list, ft_del_front, 2);
	ft_dlstadd_front(list, a);
	ft_dlstadd_front(list, b);
	return (1);
}

int	ft_push_list(t_dlist **src, t_dlist **des)
{
	t_dlist	*a;
	int		content;
	int		order;

	if (src == NULL)
		return (0);
	a = *src;
	content = a->content;
	order = a->order;
	ft_del_front(src);
	ft_dlstadd_front(des, ft_dlstnew(content, order));
	return (1);
}

int	ft_rotate_list(t_dlist **lst)
{
	t_dlist	*current;
	int		content;
	int		order;

	current = *lst;
	if (current == NULL)
		return (0);
	content = current->content;
	order = current->order;
	ft_dlstadd_back(lst, ft_dlstnew(content, order));
	ft_del_front(lst);
	return (1);
}

int	ft_re_rotate_list(t_dlist **lst)
{
	t_dlist	*current;
	int		content;
	int		order;

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
	order = current->order;
	ft_dlstadd_front(lst, ft_dlstnew(content, order));
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
