/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abx <abx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:25:44 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/22 21:44:59 by abx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check_input(int ac)
{
	if (ac != 5)
	{
		ft_printf("%s", "Wrong Number of arguments");
		return (0);
	}
	return (1);
}

void	first_command(int first_fd, int wr_fd, char **av, char **envp)
{
	int		i;
	char	**path_tab;
	char	**arg_tab;
	char	*cpy;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	cpy = envp[i] + 5;
	path_tab = ft_split(cpy, ':');
	arg_tab = ft_split(av[2], ' ');
	dup2(wr_fd, STDOUT_FILENO);
	dup2(first_fd, STDIN_FILENO);
	close(wr_fd);
	close(first_fd);
	if (access(arg_tab[0], X_OK) == 0)
		execv(arg_tab[0], arg_tab);
	exec_command(arg_tab, path_tab);
}

void	second_command(int second_fd, int rd_fd, char **av, char **envp)
{
	int		i;
	char	**path_tab;
	char	**arg_tab;
	char	*cpy;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	cpy = envp[i] + 5;
	path_tab = ft_split(cpy, ':');
	arg_tab = ft_split(av[3], ' ');
	dup2(rd_fd, STDIN_FILENO);
	dup2(second_fd, STDOUT_FILENO);
	close(rd_fd);
	close(second_fd);
	if (access(arg_tab[0], X_OK) == 0)
		execv(arg_tab[0], arg_tab);
	exec_command(arg_tab, path_tab);
}

int	do_command(t_two_pid *pidfork, int *fd_tab, char **envp, char **av)
{
	pidfork->pid1 = fork();
	if (pidfork->pid1 == 0)
	{
		close(fd_tab[0]);
		first_command(pidfork->first_fd, fd_tab[1], av, envp);
		exit(0);
	}
	pidfork->pid2 = fork();
	if (pidfork->pid2 == 0)
	{
		close(fd_tab[1]);
		second_command(pidfork->second_fd, fd_tab[0], av, envp);
		exit(0);
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int			fd_tab[2];
	t_two_pid	*pidfork;

	pidfork = malloc(sizeof(t_two_pid));
	pipe(fd_tab);
	if (!check_input(ac))
		return (EXIT_FAILURE);
	pidfork->first_fd = open(av[1], O_RDONLY);
	pidfork->second_fd = open(av[4], O_WRONLY | O_CREAT, 0666);
	if (pidfork->first_fd == -1 || pidfork->second_fd == -1)
	{
		perror("Error opening files");
		return (EXIT_FAILURE);
	}
	if (!do_command(pidfork, fd_tab, envp, av))
		return (0);
	close(fd_tab[0]);
	close(fd_tab[1]);
	waitpid(pidfork->pid1, NULL, 0);
	waitpid(pidfork->pid2, NULL, 0);
	close(pidfork->first_fd);
	close(pidfork->second_fd);
	return (EXIT_SUCCESS);
}
