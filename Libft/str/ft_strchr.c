/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:41:45 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/18 16:44:35 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	const char *str = "Hello, World!";
	int c = 'o';

	char *result = ft_strchr(str, c);
	if (result != NULL)
	{
		printf("Le caractère '%c' a été trouvé à la position : %ld\n", c,
			result - str);
	}
	else
	{
		printf("Le caractère '%c' n'a pas été trouvé dans la chaîne.\n",
			c);
	}
	return (0);
}*/