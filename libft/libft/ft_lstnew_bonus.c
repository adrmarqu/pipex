/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:37:04 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/16 13:55:07 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

content:	el contenido co el que crea el nodo

return:		el nuevo nodo

desc:		Crea un nuevo nodo utilizando malloc. La variable content
			se inicializa con content y la variable next con NULL

*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lista;

	lista = (t_list *)malloc(sizeof(t_list));
	if (!lista)
		return (NULL);
	lista->content = content;
	lista->next = NULL;
	return (lista);
}
