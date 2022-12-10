/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:05:12 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/12/10 16:54:54 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define LAST 99999
# define MIDDLE -3
# define FIRST -4

typedef struct s_dlist
{
	int				content;
	int				index;
	int				order;
	struct s_dlist	*previous;
	struct s_dlist	*next;
}	t_dlist;

typedef struct s_chunk
{
	int		start;
	int		end;
	int		counter;
	int		temp;
	int		index;
	t_dlist	*current;
	t_dlist	*big;
	t_dlist	*small;
}	t_chunk;

typedef struct s_hold
{
	int	_1;
	int	_2;
}	t_hold;

typedef struct s_data
{
	t_dlist	*a;
	t_dlist	*b;
	t_hold	hold;

	int		total_int;
	char	**str;
	int		*i;
	t_chunk	chunk;
}	t_data;

/*			Error checks							*/
void		ps_initialize(t_data *data);
void		error_checks(char **argv, t_data *data);
void		check_char(char **argv);
void		integer_count(char **argv, t_data *data);
void		check_min_max(char *str);
void		make_int_array(char **argv, t_data *data);

/*			Everything for my double linked list	*/
t_dlist		*ft_dlstnew(int content, int order);
void		ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void		ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void		ft_del_front(t_dlist **lst);
void		ft_del_back(t_dlist **lst);
void		make_int_list(t_data *data);
t_dlist		*ft_move_down(t_dlist *lst, int i);
void		ft_repeat_op(t_data *data, void (*op)(t_data *), int repeat);
void		ft_repeat_lst(t_dlist **lst, void (*op)(t_dlist **), int repeat);
void		free_lst(t_data *data);
void		correct_index(t_dlist *lst, int start);

/*			Operations Utils						*/
int			ft_swap_list(t_dlist **list);
int			ft_push_list(t_dlist **src, t_dlist **des);
int			ft_rotate_list(t_dlist **lst);
int			ft_re_rotate_list(t_dlist **lst);

/*			Push_swap Operations					*/
void		ft_sa(t_data *data);
void		ft_sb(t_data *data);
void		ft_ss(t_data *data);
void		ft_pa(t_data *data);
void		ft_pb(t_data *data);
void		ft_ra(t_data *data);
void		ft_rb(t_data *data);
void		ft_rr(t_data *data);
void		ft_rra(t_data *data);
void		ft_rrb(t_data *data);
void		ft_rrr(t_data *data);

/*			Sorting Functions						*/
void		sort_for_3(t_data *data);
void		sort_for_5(t_data *data);
void		sort_for_100(t_data *data);

/*			Sort for 5 Utils						*/
int			ft_5_lst_len(t_dlist *a);
int			ft_check_ascending(t_data *data);
int			ft_5_find_position(t_dlist *a, t_dlist *b);
int			ft_check_insert(t_data *data);

/*			Label Order Function					*/
void		label_order(t_data *data);

/*			Sort for 100 Utils						*/
void		push_to_b_100(t_data *data);
int			lst_len(t_dlist *lst);
void		insertion_sort(t_data *data);
int			ft_100_find_position(t_data *data);
t_dlist		*get_smallest(t_data *data);
int			check_if_smallest(int smallest, int content);
void		hold_1(t_data *data);
void		hold_2(t_data *data);
int			calculate_steps(t_data *data, int hold);
void		compare_steps(t_data *data);
void		operations_100(t_data *data, int h1_steps, int h2_steps);

/*			Sort for 500 Utils						*/
void		sort_for_500(t_data *data);

/*			Find Chunk								*/
void		find_chunck(t_data *data, int index);
void		hold_1(t_data *data);
void		hold_2(t_data *data);
void		print_stack(t_data *data);

#endif