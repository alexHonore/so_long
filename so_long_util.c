/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:25:09 by minkim            #+#    #+#             */
/*   Updated: 2022/06/24 00:09:01 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		move_w(param);
	else if (keycode == KEY_S)
		move_s(param);
	else if (keycode == KEY_A)
		move_a(param);
	else if (keycode == KEY_D)
		move_d(param);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void	param_init(t_param *param, char *map)
{
	int	img_width;
	int	img_height;

	param->x = 1;
	param->y = 1;
	param->collected = 0;
	param->cnt = 0;
	param->collect_cnt = 0;
	param->mlx = mlx_init();
	param->tile = mlx_xpm_file_to_image(param->mlx, \
	"./images/floor50.xpm", &img_width, &img_height);
	param->wall = mlx_xpm_file_to_image(param->mlx, \
	"./images/wall50.xpm", &img_width, &img_height);
	param->collect = mlx_xpm_file_to_image(param->mlx, \
	"./images/coin1.xpm", &img_width, &img_height);
	param->exit = mlx_xpm_file_to_image(param->mlx, \
	"./images/door50.xpm", &img_width, &img_height);
	param->player = mlx_xpm_file_to_image(param->mlx, \
	"./images/perso50.xpm", &img_width, &img_height);
	param->two_d_map = ft_split(map, '\n');
	param->time = 5000;
}

void	ft_error(int exit_code)
{
	write(1, "Error", 6);
	if (exit_code == 0)
		write(1, ": Cannot open the map file.\n", 29);
	if (exit_code == 1)
		write(1, ": Please run with a map file.\n", 31);
	if (exit_code == 2)
		write(1, ": Please run with a .ber file.\n", 31);
	exit(exit_code);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}


size_t	ft_strlen_n(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\n')
		count++;
	return (count);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}


int	exit_game(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}
