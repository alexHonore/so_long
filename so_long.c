/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:25:09 by minkim            #+#    #+#             */
/*   Updated: 2022/06/24 00:10:17 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	update_utils(t_param *param)
{
	int	img_width;
	int	img_height;

	if ((param->collect = mlx_xpm_file_to_image(param->mlx, \
	"./images/coin1.xpm", &img_width, &img_height)) && param->time == 0)
	{
		param->collect = mlx_xpm_file_to_image(param->mlx, \
		"./images/wall50.xpm", &img_width, &img_height);
		ft_printf("WORK UPDATE");
		param->time = 5000;
	}
	else if ((param->collect = mlx_xpm_file_to_image(param->mlx, \
	"./images/coin2.xpm", &img_width, &img_height)) && param->time == 0)
	{
		param->collect = mlx_xpm_file_to_image(param->mlx, \
		"./images/coin1.xpm", &img_width, &img_height);
		param->time = 5000;
	}
}


int	update(t_param	*param, char* map)
{
	if (param->time > 0)
	{
		param->time--;
		return (0);
	}
	update_utils(param);
	return (0);
}

*/

int	main(int argc, char **argv)
{
	t_param	param;
	char	*map;
	int		fd;

	if (argc != 2)
		ft_error(1);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_error(2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(0);
	map = check_map(fd);
	if (map == NULL)
		return (0);
	param_init(&param, map);
	ft_render(&param, map);
	free(map);
	mlx_hook(param.win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_hook(param.win, X_EVENT_KEY_EXIT, 0, &exit_game, &param);
	//mlx_loop_hook(param.mlx, update, &param);
	mlx_loop(param.mlx);
	return (0);
}
