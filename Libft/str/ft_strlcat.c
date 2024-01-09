/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:45:22 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:13:18 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (!src)
		return (d);
	if (size == 0 || size <= d)
		return (s + size);
	i = 0;
	while (src[i] && d + i < size - 1)
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (d + s);
}
/*
int main (void)
{
	char src[] = "Demir";
		char dest[] = "Ozan";
	printf("%s \n", ft_strlcat(dest, src, 20));
	printf("%s \n", dest);
}*/