/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:05:12 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/03 18:33:02 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_data
{
	int		total_int;
	char	**str;
	int		*i;
}	t_data;

void	ps_initialize(t_data *data);
void	error_checks(char **argv, t_data *data);
void	check_char(char **argv);
void	integer_count(char **argv, t_data *data);
void	check_min_max(char *str);
void	make_int_array(char **argv, t_data *data);

#endif