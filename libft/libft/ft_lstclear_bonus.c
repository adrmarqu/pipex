/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:02 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 13:57:07 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 
lst: 	la dirección de un puntero a un nodo.
del: 	un puntero a función utilizado para eliminar
		el contenido de un nodo.

Desc: 	Elimina y libera el nodo ’lst’ dado y todos los
		consecutivos de ese nodo, utilizando la función
		’del’ y free(3).
		Al final, el puntero a la lista debe ser NULL.

*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst2;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		lst2 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst2;
	}
}
