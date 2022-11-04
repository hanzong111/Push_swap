/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_d_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:45:43 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/04 18:12:07 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*list;

	list = malloc (sizeof(t_dlist));
	if (!list)
		return (NULL);
	list->content = content;
	list->previous = NULL;
	list->next = NULL;
	return (list);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*nextlst;
	t_dlist	*previous;

	nextlst = *lst;
	previous = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (nextlst)
	{
		if (nextlst->next == NULL)
		{
			previous = nextlst;
			nextlst->next = new;
			nextlst = nextlst->next;
			nextlst->previous = previous;
			break ;
		}
		nextlst = nextlst->next;
	}
}

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*current;
	t_dlist	*next;

	current = *lst;
	next = *lst;
	current->previous = new;
	current = current->previous;
	current->next = next;
	*lst = current;
}
