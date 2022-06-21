/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:25:09 by minkim            #+#    #+#             */
/*   Updated: 2022/06/21 14:47:26 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_invalid_char(char c, t_check *check)
{
	if (c == '\n')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == '0')
		return (0);
	else if (c == 'C')
	{	
		check->collect++;
		return (0);
	}
	else if (c == 'E')
	{	
		check->exit++;
		return (0);
	}
	else if (c == 'P')
	{	
		check->player++;
		return (0);
	}
	else
		return (1);
}

int	is_invalid_line(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_invalid_char(line[i], check))
		{
			write(1, "Error : this map is not valid.\n", 32);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_close(char *line, size_t len)
{
	if (line[0] == '1' && line[len - 2] == '1')
		return (0);
	else
		return (1);
}

int	is_not_rectangular(char *line, size_t len)
{
	if (len != ft_strlen(line) || check_close(line, len))
	{
		write(1, "Error : map must be rectangular.\n", 34);
		return (1);
	}
	return (0);
}

char	*check_cep(t_check *check, char *map)
{
	if (check->collect == 0 || check->exit == 0 || check->player == 0)
	{
		write(1, "Error : map must have at least one C/E/P each.\n", 48);
		free(map);
		return (NULL);
	}
	return (map);
}
