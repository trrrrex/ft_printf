/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavramen <aavramen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:08:12 by aavramen          #+#    #+#             */
/*   Updated: 2024/04/01 15:09:46 by aavramen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prefix(char a)
{
	int	ret;

	ret = 0;
	if (a == 'p')
	{
		ret = ft_putstr("0x");
		if (ret == -1)
			return (-1);
	}
	return (ret);
}

int	sign(ssize_t *n, int *len)
{
	int	ret;

	if (*n < 0)
	{
		*n *= -1;
		ret = write(1, "-", 1);
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	return (0);
}

int	ft_putascii(ssize_t n, int base, char c, char a)
{
	char	*str;
	int		len;
	int		ret;

	len = 0;
	ret = prefix(a);
	if (ret == -1)
		return (-1);
	len += ret;
	if (base == 10)
	{
		ret = sign(&n, &len);
		if (ret == -1)
			return (-1);
	}
	str = ft_itoa_base(n, base, c);
	if (str == 0)
		return (-1);
	ret = ft_putstr(str);
	free(str);
	len += ret;
	return (len);
}
