/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:12 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/05 11:13:04 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_nbrbase(unsigned long nbr, char *base, bool ptr)
{
	unsigned long	size;
	unsigned long	nb;
	int				cpt;

	cpt = 0;
	nb = nbr;
	if (ptr)
	{
		if (nbr == 0)
			return (cpt += ft_putstr("(nil)"));
		cpt += ft_putstr("0x");
		ptr = 0;
	}
	size = ft_strlen(base);
	if (nb > size - 1)
	{
		cpt += ft_nbrbase(nb / size, base, ptr);
	}
	cpt += ft_putchar(base[nb % size]);
	return (cpt);
}

int	ft_format(const char format, va_list args)
{
	int	cpt;

	cpt = 0;
	if (format == 'c')
		cpt += ft_putchar(va_arg(args, int));
	else if (format == 's')
		cpt += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		cpt += ft_nbrbase(va_arg(args, unsigned long), "0123456789abcdef",
				true);
	else if (format == 'd' || format == 'i')
		cpt += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		cpt += ft_putnbr_un(va_arg(args, unsigned int));
	else if (format == 'x')
		cpt += ft_nbrbase(va_arg(args, unsigned int), "0123456789abcdef",
				false);
	else if (format == 'X')
		cpt += ft_nbrbase(va_arg(args, unsigned int), "0123456789ABCDEF",
				false);
	else if (format == '%')
		cpt += ft_putchar('%');
	return (cpt);
}

int	ft_printf(const char *format, ...)
{
	int		cpt;
	int		i;
	va_list	args;

	cpt = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			cpt += ft_format(format[i + 1], args);
			i++;
		}
		else
			cpt += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (cpt);
}
