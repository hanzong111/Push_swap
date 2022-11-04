/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_int_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:33:57 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/04 18:40:15 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	make_int_list(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->total_int)
	{
		ft_dlstadd_back(&data->a, ft_dlstnew(data->i[index]));
		index++;
	}
	free(data->i);
}
