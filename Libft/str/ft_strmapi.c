/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:21:05 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:13:25 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	test_function(unsigned int index, char c)
{
	index = 1;
	return (c + index);
}

int	main(void)
{
	const char *original = "Hello, World!";

	char *result = ft_strmapi(original, test_function);

	if (result)
	{
		printf("Chaîne transformée : %s\n", result);
		free(result);
	}
	else
	{
		printf("L'allocation mémoire a échoué.\n");
	}

	return (0);
}*/