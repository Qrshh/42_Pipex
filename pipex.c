/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:41:03 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/10 18:29:34 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;
	int		i;

	i = -1;
	if (*cmd == '\0')
		exit_error("Erreur");
	args = ft_split(cmd, ' ');
	if (ft_strchr(args[0], '/') > -1)
		path = args[0];
	else
		path = getpath(args[0], env);
	execve(path, args, env);
	while (args[++i])
		free(args[i]);
	free(args);
	exit_error("command not found");
}

void	redir(char *cmd, char **env)
{
	pid_t	pid;
	int		fd_tab[2];

	if (pipe(fd_tab) == -1)
		exit_error("Erreur pipe");
	pid = fork();
	if (pid == -1)
		exit_error("Erreur fork");
	if (pid)
	{
		close(fd_tab[1]);
		dup2(fd_tab[0], STDIN_FILENO);
		close(fd_tab[0]);
	}
	else
	{
		close(fd_tab[0]);
		dup2(fd_tab[1], STDOUT_FILENO);
		close(fd_tab[1]);
		exec(cmd, env);
	}
}

int	main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;

	if (ac != 5)
		exit_error("Erreur, arguments attendu : ./pipex file1 cmd1 cmd2 file2");
	else
	{
		fd1 = open_file(av[1], 1);
		fd2 = open_file(av[4], 2);
		dup2(fd1, STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		redir(av[2], env);
		exec(av[3], env);
	}
	return (1);
}
