/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:21:23 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:10:07 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char str1[] = "Salut le boss";
	const char str2[] = "Salut le boss";
	const char str3[] = "Salut le pass";
	size_t n = 13;

	int result1 = ft_memcmp(str1, str2, n);
	int result2 = ft_memcmp(str1, str3, n);
	if (result1 == 0)
	{
		printf("str1 et str2 sont identiques.\n");
	}
	else
	{
		printf("str1 et str2 ne sont pas identiques.\n");
	}

	if (result2 == 0)
	{
		printf("str1 et str3 sont identiques.\n");
	}
	else
	{
		printf("str1 et str3 ne sont pas identiques.\n");
	}
	return (0);
}*/