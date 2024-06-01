/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:04:18 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/24 14:42:02 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **envp)
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

void	do_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		tub[2];

	if (pipe(tub) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (!pid)
	{
		close(tub[0]);
		dup2(tub[1], 1);
		execute(cmd, envp);
	}
	else
	{
		close(tub[1]);
		dup2(tub[0], 0);
	}
}
