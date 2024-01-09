/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:36:47 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:10:11 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	destination = dest;
	source = src;
	i = 0;
	if (destination < source)
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	else if (destination > source)
	{
		i = n;
		while (i > 0)
		{
			destination[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char source[] = "Buff Ksante please";
	char destination[20];
	
	ft_memmove(destination, source, sizeof(source));
	printf("Source : %s\n", source);
	printf("Destination : %s\n", destination);
}*/