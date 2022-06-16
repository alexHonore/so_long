/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:03:23 by minkim            #+#    #+#             */
/*   Updated: 2022/06/16 03:21:10 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchrr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
/*
int	ft_putstr(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (*str)
	{
		res += ft_printchar(*str, 1);
		str++;
	}
	return (res);
}
*/
int	ft_strlenn(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_put_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_printchar(c, 1);
	return (1);
}

int	ft_put_s(va_list ap)
{
	int		len;
	char	*s;
	int		res;
	int		i;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlenn(s);
	res = 0;
	i = 0;
	while (s[i] && i < len)
	{
		res += ft_printchar(s[i], 1);
		i++;
	}
	return (res);
}
