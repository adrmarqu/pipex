/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:30:56 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/17 13:41:52 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

lst: 		un puntero al primer nodo.
f: 			un puntero a la función que utilizará cada nodo.

Desc: 		Itera la lista ’lst’ y aplica la función ’f’ en el
			contenido de cada nodo.

*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
