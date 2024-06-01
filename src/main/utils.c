/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:50:15 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/24 14:33:08 by adrmarqu         ###   ########.fr       */
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

	if (!t)
		fd = open(name, O_RDONLY);
	else
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
