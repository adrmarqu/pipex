/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:03:03 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/27 12:37:34 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	make_here_doc(char **argv, int *tub)
{
	char	*line;

	close(tub[0]);
	while (1)
	{
		ft_printf("pipe heredoc> ");
		line = get_next_line(0);
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, tub[1]);
		free(line);
	}
}

void	here_doc(char **argv)
{
	pid_t	pid;
	int		tub[2];

	if (pipe(tub) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (!pid)
		make_here_doc(argv, tub);
	else
	{
		close(tub[1]);
		dup2(tub[0], 0);
		wait(NULL);
	}
}
