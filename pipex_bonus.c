/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:46:10 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/09 15:44:22 by abesneux         ###   ########.fr       */
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
	while (env[i] && ft_str_ncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_str_chr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_str_chr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_str_chr(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char **env)
{
	int		i;
	char	**args;
	char	*path;

	i = -1;
	args = ft_split(cmd, ' ');
	if (ft_str_chr(args[0], '/') > -1)
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

int	heredoc(char *lim, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;
	int	i;

	if (ac < 5)
		exit_error("Erreur, arguments attendu : ./pipex file1 cmd1 cmd2 file2");
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		if (ac < 6)
			exit_error("Erreur arguments");
		fd2 = open_file(av[ac - 1], 3);
		heredoc(av[2], fd2);
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
