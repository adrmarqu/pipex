/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:04:42 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 16:17:48 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(const char *s)
{
	ft_printf(RED "Error: %s" RESET "\n", s);
	exit(1);
}

void	ft_error(void)
{
	perror(RED "Error");
	exit(1);
}

int	ft_open(char *name, int t)
{
	int	fd;

	fd = -1;
	if (t == 0)
		fd = open(name, O_RDONLY, 0777);
	else if (t == 1)
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (t == 2)
		fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		ft_error();
	return (fd);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}
