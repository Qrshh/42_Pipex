/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:01:41 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:13:06 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_substring;

	in_substring = 0;
	count = 0;
	while (*s)
	{
		if (in_substring && *s == c)
			in_substring = 0;
		if (!in_substring && *s != c)
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	word_length(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*leak_free(char **result, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		result[i] = ft_substr(s, 0, word_length(s, c));
		if (!result[i])
			return (leak_free(result, i));
		s += word_length(s, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
/*
int	main(void)
{
	char s[] = "Tripouille";
	char c = ' ';

	char **result = ft_split(s, c);

	if (result)
	{
		int i = 0;
		while (result[i] != NULL)
		{
			printf("Word %d: %s\n", i, result[i]);
			i++;
		}
		i = 0;
		while (result[i] != NULL)
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}*/