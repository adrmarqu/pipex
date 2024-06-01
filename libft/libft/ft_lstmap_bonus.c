/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:35:31 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 18:13:47 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

lst: 		un puntero a un nodo.
f: 			la dirección de un puntero a una función usada
			en la iteración de cada elemento de la lista.
del: 		un puntero a función utilizado para eliminar
			el contenido de un nodo, si es necesario.

return:		La nueva lista o NULL si falla la reserva de memoria.

Desc:		Itera la lista ’lst’ y aplica la función ’f’ al
			contenido de cada nodo. Crea una lista resultante
			de la aplicación correcta y sucesiva de la función
			’f’ sobre cada nodo. La función ’del’ se utiliza
			para eliminar el contenido de un nodo, si hace
			falta.

*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r;
	t_list	*tmp;
	void	*p;

	if (!lst || !f)
		return (NULL);
	r = NULL;
	while (lst)
	{
		p = (f)(lst->content);
		tmp = ft_lstnew(p);
		if (!tmp)
		{
			ft_lstclear(&r, del);
			free(p);
			return (NULL);
		}
		ft_lstadd_back(&r, tmp);
		lst = lst->next;
	}
	return (r);
}
