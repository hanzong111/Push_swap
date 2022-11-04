/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:45:33 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/04 23:33:45 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_sa(t_data *data)
{
	if (ft_swap_list(data->a))
		ft_printf("sa\n");
}

void	ft_sb(t_data *data)
{
	if (ft_swap_list(data->b))
		ft_printf("sb\n");
}

void	ft_ss(t_data *data)
{
	int	a;
	int	b;

	a = ft_swap_list(data->a);
	b = ft_swap_list(data->b);
	if (a || b)
		ft_printf("ss\n");
}

void	ft_pa(t_data *data)
{
	if (ft_push_list(&data->b, &data->a))
		ft_printf("pa\n");
}

void	ft_pb(t_data *data)
{
	if (ft_push_list(&data->a, &data->b))
		ft_printf("pb\n");
}
