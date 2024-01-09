/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:32:21 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:13:33 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_a_sep(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	size;
	char	*dest;
	size_t	i;

	if (!s1)
		return (NULL);
	size = 0;
	while (is_a_sep(set, *s1))
		s1++;
	while (*s1++)
		size++;
	while (size > 0 && is_a_sep(set, *(s1 - 2)))
	{
		size--;
		s1--;
	}
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < (size))
		dest[i++] = *(s1++ - (size + 1));
	dest[i] = 0;
	return (dest);
}
/*
int	main(void)
{
	char *s1 = "  Salut mec  ";
	char *set = " ";

	printf("%s", ft_strtrim(s1, set));
}*/