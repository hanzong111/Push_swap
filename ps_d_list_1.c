/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_d_list_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:45:43 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/18 20:29:11 by ojing-ha         ###   ########.fr       */
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

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	next = *lst;
	current->previous = new;
	current = current->previous;
	current->next = next;
	*lst = current;
}

void	ft_del_front(t_dlist **lst)
{
	t_dlist	*temp;
	t_dlist	*current;

	temp = *lst;
	current = temp->next;
	free (temp);
	if (current == NULL)
	{
		*lst = NULL;
		return ;
	}
	current->previous = NULL;
	*lst = current;
}

void	ft_del_back(t_dlist **lst)
{
	t_dlist	*temp;
	t_dlist	*current;

	temp = *lst;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	current = temp->previous;
	free(temp);
	current->next = NULL;
	while (current)
	{
		if (current->previous == NULL)
			break ;
		current = current->previous;
	}
	*lst = current;
}
