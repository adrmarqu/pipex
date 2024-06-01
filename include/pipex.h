/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:11:39 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 16:16:12 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>  
# include "../libft/ft_printf/ft_printf.h"
# include "color.h"

int		ft_open(char *name, int t);
void	ft_free(char **s);

char	*get_path(char *cmd, char **env);

void	child(char **argv, int *end, char **envp);
void	parent(char **argv, int *end, char **envp);

void	print_error(const char *s);
void	ft_error(void);

void	execute(char *cmd, char **envp);
void	do_pipe(char *cmd, char **envp);
void	here_doc(char **argv);

#endif
