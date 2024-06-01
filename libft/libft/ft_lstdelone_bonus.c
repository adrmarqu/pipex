/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:20:29 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/17 13:39:11 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

lst: 	el nodo a liberar.
del: 	un puntero a la función utilizada para liberar
		el contenido del nodo.

Desc:	Toma como parámetro un nodo ’lst’ y libera la
		memoria del contenido utilizando la función ’del’
		dada como parámetro, además de liberar el nodo. La
		memoria de ’next’ no debe liberarse

*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	lst = NULL;
}
