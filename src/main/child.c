/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:05:10 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/06/01 12:57:47 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], envp);
	if (execve(path, s_cmd, envp) == -1)
	{
		ft_free(s_cmd);
		ft_error();
	}
}

void	child(char **argv, int *end, char **envp)
{
	int		fd;

	fd = ft_open(argv[1], 0);
	dup2(fd, 0);
	dup2(end[1], 1);
	close(end[0]);
	exec(argv[2], envp);
}

void	parent(char **argv, int *end, char **envp)
{
	int		fd;

	fd = ft_open(argv[4], 1);
	dup2(fd, 1);
	dup2(end[0], 0);
	close(end[1]);
	exec(argv[3], envp);
}
