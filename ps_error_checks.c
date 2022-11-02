/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:38:54 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/02 19:46:43 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_char(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i] != NULL)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (!((argv[i][k] >= '0' && argv[i][k] <= '9')
					|| argv[i][k] == ' ' || argv[i][k] == '-'))
			{
				ft_printf("Invalid integer character : %c\n", argv[i][k]);
				exit (0);
			}
			k++;
		}
		i++;
	}
}

void	integer_count(char **argv, t_data *data)
{
	int	index;
	int	i;

	index = 1;
	while (argv[index] != NULL)
	{
		i = -1;
		data->str = ft_split(argv[index], ' ');
		while (data->str[++i] != NULL)
			data->total_int++;
		i = -1;
		while (data->str[++i] != NULL)
			free(data->str[i]);
		free(data->str);
		index++;
	}
}

void	check_min_max(char **str)
{

}

void	make_int_array(char **argv, t_data *data)
{
	int	j;
	int	k;
	int	index;

	index = 0;
	j = 1;
	data->i = malloc(sizeof(int) * data->total_int);
	while (index != data->total_int)
	{
		k = -1;
		data->str = ft_split(argv[j], ' ');
		while (data->str[++k] != NULL)
		{
			check_min_max(data->str[k]);
			data->i[index] = ft_atoi(data->str[k]);
			index++;
		}
		k = -1;
		while (data->str[++k] != NULL)
			free(data->str[k]);
		free(data->str);
		j++;
	}
}

void	check_duplicate(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	integer_count(argv, data);
	make_int_array(argv, data);
	while (i < data->total_int)
	{
		j = 1;
		while ((i - j) >= 0)
		{
			if (data->i[i] == data->i[i - j])
			{
				ft_printf("Error\n");
				free(data->i);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	error_checks(char **argv, t_data *data)
{
	check_char(argv);
	check_duplicate(argv, data);
}
