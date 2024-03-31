/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavramen <aavramen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:32:51 by aavramen          #+#    #+#             */
/*   Updated: 2024/03/29 18:34:38 by aavramen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list *arg, int *len)
{	
	len = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putascii(va_arg(*arg, signed int), B_10, DEC, SIG));
	if (c == 'u')
		return (ft_putascii(va_arg(*arg, unsigned int), B_10, DEC, NO_FLAG));
	if (c == 'p')
		return (ft_putascii(va_arg(*arg, unsigned long long), B_16, LHEX, PTR));
	if (c == 'x')
		return (ft_putascii(va_arg(*arg, unsigned int), B_16, LHEX, NO_FLAG));
	if (c == 'X')
		return (ft_putascii(va_arg(*arg, unsigned int), B_16, UHEX, NO_FLAG));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		ret;
	int		i;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret = ft_format(str[i], &arg, &len);
			if (ret == -1)
				return (-1);
			len += ret;
			i++;
		}
		elsec
		{
			ret = ft_putchar(str[i++]);
			if (ret == -1)
				return (-1);
			len += ret;
		}
	}
	return (len);
}

