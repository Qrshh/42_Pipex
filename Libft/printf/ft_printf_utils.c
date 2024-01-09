/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:41:04 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/05 10:59:08 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		cpt += ft_putchar(str[i]);
		i++;
	}
	return (cpt);
}

int	ft_putnbr(int n)
{
	int	cpt;

	cpt = 0;
	if (n == INT_MAX)
		cpt += ft_putstr("2147483647");
	else if (n == INT_MIN)
		cpt += ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			cpt += ft_putchar('-');
			n = -n;
		}
		if (n > 9)
			cpt += ft_putnbr(n / 10);
		cpt += ft_putchar((n % 10) + '0');
	}
	return (cpt);
}

int	ft_putnbr_un(unsigned int n)
{
	unsigned int	cpt;

	cpt = 0;
	if (n > 9)
		cpt += ft_putnbr_un(n / 10);
	cpt += ft_putchar((n % 10) + '0');
	return (cpt);
}
