/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:48:22 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:10:09 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	destination = dest;
	source = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char source[] = "Salut";
	char destination[20];

	ft_memcpy(destination, source, sizeof(source));
	printf("Source : %s\n", source);
	printf("Destination : %s\n", destination);
	return (0);
}*/