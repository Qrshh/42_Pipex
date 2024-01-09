/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:55 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:10:05 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		target;

	str = s;
	target = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == target)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*str = "Hello, World!";
	int			c;
	void		*result;

	c = 'o';
	size_t n = 13;
	result = ft_memchr(str, c, n);
	if (result != NULL)
	{
		printf("Le caractère '%c' a été trouvé à la position : %ld\n", c,
			(char *)result - str);
	}
	else
	{
		printf("Le caractère '%c' n'a pas été trouvé dans la chaîne.\n", c);
	}
	return (0);
}*/