/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:05:12 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/04 18:41:36 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*previous;
	struct s_dlist	*next;
}	t_dlist;

typedef struct s_data
{
	t_dlist	*a;
	t_dlist	*b;

	int		total_int;
	char	**str;
	int		*i;
}	t_data;

void		ps_initialize(t_data *data);
void		error_checks(char **argv, t_data *data);
void		check_char(char **argv);
void		integer_count(char **argv, t_data *data);
void		check_min_max(char *str);
void		make_int_array(char **argv, t_data *data);

t_dlist		*ft_dlstnew(int content);
void		ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void		ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void		make_int_list(t_data *data);

#endif