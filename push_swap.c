/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:16:01 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/30 02:34:13 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	char_check(char *argv)
{
	while (*argv != '\0')
	{
		if (!((*argv >= '0' && *argv <= '9') || *argv == ' ' || *argv == '-'))
		{
			ft_printf("Invalid int\n");
			exit (0);
		}
		argv++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char_check(argv[1]);
	}
	return (0);
}