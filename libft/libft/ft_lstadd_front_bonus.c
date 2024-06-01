/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:43:52 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/16 14:16:28 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

lst:	direccion de un puntero al primer nodo de una lista
new:	un puntero al nodo que anadir al principio de la lista

desc:	Anade el nodo 'new' al principio de la lista 'lst'.

*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
