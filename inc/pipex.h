/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abx <abx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:56:50 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:48 by abx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/inc/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_two_pid
{
	pid_t	pid1;
	pid_t	pid2;
	int		first_fd;
	int		second_fd;
}			t_two_pid;

int			check_input(int ac);
void		exec_command(char **arg_tab, char **path_tab);
void		free_tab(char **tab);
int			do_command(t_two_pid *pidfork, int *fd_tab, char **envp, char **av);
void		first_command(int first_fd, int wr_fd, char **av, char **envp);

#endif
