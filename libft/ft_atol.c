/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:15:35 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/03 18:44:40 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *str)
{
	char			*str1;
	int				sign;
	long int		sum;

	sum = 0;
	sign = 1;
	str1 = (char *)str;
	while (*str1 == ' ' || *str1 == '\t' || *str1 == '\n' || *str1 == '\f'
		|| *str1 == '\r' || *str1 == '\v')
		str1++;
	if (*str1 == '-')
		sign = -1;
	if (*str1 == '-' || *str1 == '+')
		str1++;
	while (*str1 >= '0' && *str1 <= '9')
	{
		sum = sum * 10 + *str1 - '0';
		// if ((sum * sign) > 2147483647)
		// 	return (-1);
		// if ((sum * sign) < -2147483648)
		// 	return (0);
		str1++;
	}
	return (sum * sign);
}
