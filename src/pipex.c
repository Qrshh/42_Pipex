/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:25:44 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/08 07:24:16 by abesneux         ###   ########.fr       */
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
		return (0);
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
	arg_tab = ft_split(av[3], ' ');
	/*Verifier si le binaire n'est pas dans le dossier courant*/
	if (access(arg_tab[0], X_OK) == 0)
	/* verifier que la commande est executable (binaire == fichier executable de la commande en gros)*/
	{
		free(path_tab);
		execv(arg_tab[0], arg_tab);
		/* execv empeche la suite du code car entame le lancement du processus*/
	}
	exec_command(arg_tab, path_tab);
}

int	do_command(t_two_pid pidfork, int *fd_tab, char **envp, char **av)
{
	/*
	Fonctions qui doit retourner 0 dans le cas ou ca ne fonctionne pas
	*/
	pidfork.pid1 = fork(); /* creation premier fork*/
	if (pidfork.pid1 == 0)
	/* si c'est egal a 0 bah on execute first_command (car premier fork donc premier processus)*/
	{
		close(fd_tab[0]);
		first_command(pidfork.first_fd, av[2], fd_tab[1], envp);
		exit(0);
	}
	pidfork.pid2 = fork();
	if (pidfork.pid2 == 0)
	{
		close(fd_tab[1]);
		/* appel a la methode second_command*/
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
	if (!do_command(&pidfork, fd_tab, envp, av))
		/* IL FAUT FAIRE UNE METHODE DO_COMMAND QUI VA EXECUTER LES COMMANDES EN FAISANT LES APPELS AUX AUTRES*/
		return (0);
	close(fd_tab[0]);
	close(fd_tab[1]);
	waitpid(pidfork.pid1, NULL, 0);
	waitpid(pidfork.pid2, NULL, 0);
	close(pidfork.first_fd);
	close(pidfork.second_fd);
	return (EXIT_SUCCESS);
}
