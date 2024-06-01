/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:52:17 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/17 13:31:21 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

lst:	El prinicipio de la lista

return:	Longitud de la lista

desc:	Cuenta el nummero de nodos de una lista

*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}
