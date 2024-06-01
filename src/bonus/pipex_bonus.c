/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:04:32 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/24 14:41:21 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_arg(int argc, char *docs)
{
	if (argc < 5)
		print_error("Too few arguments");
	if (!ft_strcmp("here_doc", docs))
	{
		if (argc < 6)
			print_error("Too few arguments");
		else if (argc > 6)
			print_error("Too many arguments");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	i;

	if (check_arg(argc, argv[1]))
	{
		i = 3;
		fd[1] = ft_open(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		fd[0] = ft_open(argv[1], 0);
		fd[1] = ft_open(argv[argc - 1], 1);
		dup2(fd[0], 0);
	}
	while (i < argc - 2)
	{
		do_pipe(argv[i], envp);
		i++;
	}
	dup2(fd[1], 1);
	execute(argv[argc - 2], envp);
	exit(0);
}
