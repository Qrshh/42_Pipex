/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:06:37 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:10:13 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int tab[5];
	int i;

	i = 0;
	ft_memset(tab, 0, sizeof(tab));
	while (i < 5)
	{
		printf("%d", tab[i]);
				i++;
	}
	return (0);
}*/