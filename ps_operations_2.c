/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:56:43 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/18 20:33:43 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_ra(t_data *data)
{
	if (ft_rotate_list(&data->a))
		ft_printf("ra\n");
	correct_index(data->a, 0);
}

void	ft_rb(t_data *data)
{
	if (ft_rotate_list(&data->b))
		ft_printf("rb\n");
}

void	ft_rr(t_data *data)
{
	int	a;
	int	b;

	a = ft_rotate_list(&data->a);
	b = ft_rotate_list(&data->b);
	if (a || b)
		ft_printf("rr\n");
	correct_index(data->a, 0);
}

void	ft_rra(t_data *data)
{
	if (ft_re_rotate_list(&data->a))
		ft_printf("rra\n");
	correct_index(data->a, 0);
}

void	ft_rrb(t_data *data)
{
	if (ft_re_rotate_list(&data->b))
		ft_printf("rrb\n");
}
