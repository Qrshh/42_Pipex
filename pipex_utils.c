/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:04:07 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/08 16:05:57 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

int	open_file(char *filename, int mode)
{
	int	fd;

	if (mode == 1)
		fd = (open(filename, O_RDONLY));
	if (mode == 2)
		fd = (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	if (mode == 3)
		fd = (open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644));
	return (fd);
}

int	ft_str_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

int	ft_str_ncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s2[i] - s1[i]);
}

char	*path_join(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (ft_str_chr(path, 0) + ft_str_chr(bin, 0)
				+ 2));
	i = 0;
	j = 0;
	while (path[j])
	{
		joined[i] = path[j];
		i++;
		j++;
	}
	joined[i] = '/';
	i++;
	j = 0;
	while (bin[j])
	{
		joined[i] = bin[j];
		i++;
		j++;
	}
	joined[i] = 0;
	return (joined);
}
