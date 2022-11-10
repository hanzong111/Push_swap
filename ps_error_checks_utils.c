/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_checks_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:38:54 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/11/10 19:06:37 by ojing-ha         ###   ########.fr       */
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
		if (argv[i][k] == '\0')
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		while (argv[i][k] != '\0')
		{
			if (!(ft_isdigit(argv[i][k])
				|| argv[i][k] == ' ' || argv[i][k] == '-' || argv[i][k] == '+'))
			{
				write(2, "Error\n", 6);
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

void	check_str(char *str)
{
	char	*ptr;

	ptr = str;
	if (*ptr == '+' || *ptr == '-')
		ptr++;
	if (!ft_isalnum(*ptr))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	while (ft_isalnum(*ptr))
		ptr++;
	if (*ptr != '\0' || ft_atol(str) > 2147483647
		|| ft_atol(str) < -2147483648)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
}

void	make_int_array(char **argv, t_data *data)
{
	int	j;
	int	k;
	int	index;

	index = 0;
	j = 1;
	if (data->total_int == 0)
		exit (0);
	data->i = malloc(sizeof(int) * data->total_int);
	while (index != data->total_int)
	{
		k = -1;
		data->str = ft_split(argv[j], ' ');
		while (data->str[++k] != NULL)
		{
			check_str(data->str[k]);
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
