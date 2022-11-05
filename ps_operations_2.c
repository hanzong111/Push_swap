/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:56:43 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/05 15:02:22 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_ra(t_data *data)
{
	if (ft_rotate_list(&data->a))
		ft_printf("ra\n");
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
}

void	ft_rra(t_data *data)
{
	if (ft_re_rotate_list(&data->a))
		ft_printf("rra\n");
}

void	ft_rrb(t_data *data)
{
	if (ft_re_rotate_list(&data->b))
		ft_printf("rrb\n");
}
