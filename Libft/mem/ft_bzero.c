/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:26:27 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:10:02 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char tab[] = "Salut";
	size_t len = sizeof(tab) - 1;
	printf("Avant ft_bzero : %s\n", tab);
	ft_bzero(tab, len);
	printf("Après ft_bzero : %s\n", tab);
	return (0);
}*/