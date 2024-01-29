/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:04:07 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/11 17:08:49 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strchr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strchr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strchr(path, ':') + 1;
	}
	return (cmd);
}

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
	if (fd == -1)
		exit_error("Pas de fichier INFILE");
	return (fd);
}

char	*path_join(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (ft_strchr(path, 0) + ft_strchr(bin, 0)
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
