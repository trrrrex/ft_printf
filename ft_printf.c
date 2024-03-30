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

void	ft_format(char c, va_list *arg, int *len)
{
	if (c == 'c')
		*len += ft_putchar(va_arg(*arg, int));
	if (c == 's')
		*len += ft_putstr(va_arg(*arg, char *));
	if (c == 'd' || c == 'i')
		*len += ft_putascii(va_arg(*arg, signed int), B_10, DEC, SIG);
	if (c == 'u')
		*len += ft_putascii(va_arg(*arg, unsigned int), B_10, DEC, NO_FLAG);
	if (c == 'p')
		*len += ft_putascii(va_arg(*arg, unsigned long long), B_16, LHEX, PTR);
	if (c == 'x')
		*len += ft_putascii(va_arg(*arg, unsigned int), B_16, LHEX, NO_FLAG);
	if (c == 'X')
		*len += ft_putascii(va_arg(*arg, unsigned int), B_16, UHEX, NO_FLAG);
	if (c == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(str[i], &arg, &len);
			i++;
		}
		else
			len += ft_putchar(str[i++]);
	}
	return (len);
}
