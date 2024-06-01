/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:44 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/24 14:28:26 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_arg(int argc)
{
	if (argc < 5)
		print_error("Too few arguments");
	if (argc > 5)
		print_error("Too many arguments");
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];
	pid_t	pid;

	check_arg(argc);
	if (pipe(end) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (!pid)
		child(argv, end, envp);
	parent(argv, end, envp);
	exit(0);
}
