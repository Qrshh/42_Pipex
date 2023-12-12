/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:25:44 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/12 16:22:36 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* < file1 cmd1 | cmd2 > file2
	Cette commande redirige l'entree std du programme cmd1 pour lire dans le contenu du fichier file1
	cmd1 | cmd2 prend la sortie de cmd1 et la met en entree de cmd2 grace au pipe
	> file2 redirige la sortie std de cmd2 vers le fichier file2 ecrasant le contenu si il y a deja qq chose
*/

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
/*METHODE QUI PERMET D'EXECUTER LA PREMIERE COMMANDE AVANT LE PIPE*/
void	first_command(int first_fd, int wr_fd, char **av, char **envp)
/* wr_fd bout d'ecriture du pipe*/
{
	int i;
	i = 0;
	char **path_tab;
	char **arg_tab;
	char *cpy;

	/*On cherche la ligne qui contient tout les chemins d'acces au binaire (par exemple pour acceder a cat)*/
	while (ft_strncmp(envp[i], "PATH=", 5))
		/* si c'est 0 on trouve la bonne ligne (celle qui commence par PATH)*/
		i++;
	cpy = envp[i] + 5;
	path_tab = ft_split(cpy, ':'); /*on split tout les binaires possible*/
	arg_tab = ft_split(av[2], ' ');
	/*Verifier si le binaire n'est pas dans le dossier courant*/

	

	// Redirection de la sortie standard vers le descripteur de fichier du fichier de sortie
	dup2(wr_fd, STDOUT_FILENO);
	dup2(first_fd, STDIN_FILENO);

	close(wr_fd);
	close(first_fd);
	if (access(arg_tab[0], X_OK) == 0)
	/* verifier que la commande est executable (binaire == fichier executable de la commande en gros)*/
	{
		execv(arg_tab[0], arg_tab);
		/* execv empeche la suite du code car entame le lancement du processus*/
	}
	exec_command(arg_tab, path_tab);
}

void	second_command(int second_fd, int rd_fd, char **av, char **envp)
{
	int i;
	char **path_tab;
	char **arg_tab;
	char *cpy;

	i = 0;
	while(ft_strncmp(envp[i], "PATH=", 5))
		i++;
	cpy = envp[i] + 5;
	path_tab = ft_split(cpy, ':');
	arg_tab = ft_split(av[3], ' ');

	// Redirection de l'entrée standard vers le descripteur de fichier du pipe
	dup2(rd_fd, STDIN_FILENO);

	// Redirection de la sortie standard vers le descripteur de fichier du fichier de sortie
	dup2(second_fd, STDOUT_FILENO);

	close(rd_fd);
	close(second_fd);

	if (access(arg_tab[0], X_OK) == 0)
		execv(arg_tab[0], arg_tab);
	exec_command(arg_tab, path_tab);
}


int	do_command(t_two_pid pidfork, int *fd_tab, char **envp, char **av)
{
	/*
	Fonction qui doit retourner 0 dans le cas ou ca ne fonctionne pas tah return(EXIT_FAILURE);	*/
	pidfork.pid1 = fork(); /* creation premier fork*/
	if (pidfork.pid1 == 0)
	/* si c'est egal a 0 bah on execute first_command (car premier fork donc premier processus)*/
	{
		close(fd_tab[0]);
		first_command(pidfork.first_fd, fd_tab[1], av, envp);
		exit(0);
	}
	pidfork.pid2 = fork();
	if (pidfork.pid2 == 0)
	{
		close(fd_tab[1]);
		second_command(pidfork.second_fd, fd_tab[0], av, envp);
		exit(0);
	}
	return (1);
}
int	main(int ac, char **av, char **envp)
{
	int			fd_tab[2];
	t_two_pid	pidfork;

	/*besoin de deux forks pour pouvoir executer les deux commandes ensemble,
	car on doit pas attendre que l'une soit finie avant que l'autre se lance*/
	pipe(fd_tab);
	if (!check_input(ac))
		return (EXIT_FAILURE);
	pidfork.first_fd = open(av[1], O_RDONLY);
	pidfork.second_fd = open(av[4], O_WRONLY | O_CREAT, 0666);
	if (pidfork.first_fd == -1 || pidfork.second_fd == -1)
	{
		perror("Error opening files");
		return (EXIT_FAILURE);
	}
	if (!do_command(pidfork, fd_tab, envp, av))
		return (0);
	close(fd_tab[0]);
	close(fd_tab[1]);
	waitpid(pidfork.pid1, NULL, 0);
	waitpid(pidfork.pid2, NULL, 0);
	close(pidfork.first_fd);
	close(pidfork.second_fd);
	return (EXIT_SUCCESS);
}
