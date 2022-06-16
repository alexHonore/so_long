/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:15:51 by minkim            #+#    #+#             */
/*   Updated: 2022/06/16 03:21:18 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putx(unsigned int ud)
{
	int	res;

	res = 0;
	if (ud / 16)
		res += ft_putx(ud / 16);
	if ((ud % 16) >= 10)
		res += ft_printchar((ud % 16) - 10 + 'a', 1);
	else
		res += ft_printchar((ud % 16) + '0', 1);
	return (res);
}

int	ft_putxx(unsigned int ud)
{
	int	res;

	res = 0;
	if (ud / 16)
		res += ft_putxx(ud / 16);
	if ((ud % 16) >= 10)
		res += ft_printchar((ud % 16) - 10 + 'A', 1);
	else
		res += ft_printchar((ud % 16) + '0', 1);
	return (res);
}

int	ft_put_x(t_args *args, va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	if (args->c == 'x')
		return (ft_putx(d));
	else if (args->c == 'X')
		return (ft_putxx(d));
	return (0);
}

int	ft_putp(unsigned long ul)
{
	int	res;

	res = 0;
	if (ul / 16)
		res += ft_putp(ul / 16);
	if ((ul % 16) >= 10)
		res += ft_printchar((ul % 16) - 10 + 'a', 1);
	else
		res += ft_printchar((ul % 16) + '0', 1);
	return (res);
}

int	ft_put_p(va_list ap)
{
	ft_printstr("0x", 1);
	return (2 + ft_putp((unsigned long)va_arg(ap, void *)));
}
