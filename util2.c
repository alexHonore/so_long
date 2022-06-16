/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:03:23 by minkim            #+#    #+#             */
/*   Updated: 2022/06/16 03:21:15 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_puti(int d)
{
	int	res;

	res = 0;
	if (d == -2147483648)
	{
		res += ft_printchar('-', 1);
		res += ft_printstr("2147483648", 1);
		return (res);
	}
	if (d < 0)
	{
		res += ft_printchar('-', 1);
		d *= -1;
	}
	if (d / 10)
		res += ft_puti(d / 10);
	res += ft_printchar((d % 10) + '0', 1);
	return (res);
}

int	ft_put_d(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	return (ft_puti(d));
}

int	ft_putu(unsigned int u)
{
	int	res;

	res = 0;
	if (u / 10)
		res += ft_putu(u / 10);
	res += ft_printchar((u % 10) + '0', 1);
	return (res);
}

int	ft_put_u(va_list ap)
{
	int	u;

	u = va_arg(ap, int);
	return (ft_putu(u));
}
