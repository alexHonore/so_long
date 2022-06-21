/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:25:09 by minkim            #+#    #+#             */
/*   Updated: 2022/06/21 14:46:40 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_init(t_check *check)
{
	check->collect = 0;
	check->exit = 0;
	check->player = 0;
}

int	line_not_full_walls(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (line[i] != '1')
		{
			write(1, "Error : map must be surrounded by the walls.\n", 46);
			return (1);
		}
		i++;
	}
	return (0);
}

int	last_line_not_full_walls(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (line[i] != '1')
		{
			write(1, "Error : map must be surrounded by the walls.\n", 46);
			free(line);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_str_free(char *line, char *map)
{
	free(line);
	free(map);
	return (NULL);
}

char	*check_map(int fd)
{
	char	*map;
	char	*line;
	char	*lastline;
	t_check	check;

	check_init(&check);
	line = get_next_line(fd);
	check.len = ft_strlen(line);
	map = ft_strndup(line, check.len);
	if (line_not_full_walls(line, check.len))
		return (ft_str_free(line, map));
	while (line)
	{
		if (is_not_rectangular(line, check.len) || is_invalid_line(line, &check))
			return (ft_str_free(line, map));
		lastline = ft_strndup(line, check.len);
		free(line);
		line = get_next_line(fd);
		if (line)
			map = ft_strjoin(map, line);
		else if (last_line_not_full_walls(lastline, check.len))
			return (ft_str_free(line, map));
		free(lastline);
	}
	return (check_cep(&check, map));
}
