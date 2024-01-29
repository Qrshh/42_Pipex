/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:46:10 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/29 16:22:44 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	int		i;
	char	**args;
	char	*path;

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

void	heredoc2(char **av, int *fd_tab)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(fd_tab[1], line, ft_strlen(line));
		free(line);
	}
}

void	heredoc(char **av)
{
	pid_t	pid;
	int		fd_tab[2];

	if (pipe(fd_tab) == -1)
		exit_error("Erreur pipe");
	pid = fork();
	if (pid == -1)
		exit_error("Erreur fork");
	if (!pid)
		heredoc2(av, fd_tab);
	else
	{
		close(fd_tab[1]);
		dup2(fd_tab[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;
	int	i;

	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		if (ac < 6)
			exit_error("Erreur arguments");
		fd2 = open_file(av[ac - 1], 3);
		heredoc(av);
	}
	else
	{
		i = 2;
		fd1 = open_file(av[1], 1);
		fd2 = open_file(av[ac - 1], 2);
		dup2(fd1, STDIN_FILENO);
	}
	dup2(fd2, STDOUT_FILENO);
	while (i < ac - 2)
		redir(av[i++], env);
	exec(av[i], env);
}
