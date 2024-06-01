/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:26:30 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 14:14:01 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	r;
	int	sign;

	r = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		++str;
	}
	return (r * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	//const char str[] = "\t\v\f\r\n \f- \f\t\n\r    06050";
	//const char str2[] = "\t\v\f\r\n \f-06050";
	const char str[] = "\001 06050";

	printf("\nORIGINAL: %d\n", atoi(str));
	printf("MIO: %d\n", ft_atoi(str));
	//printf("\nORIGINAL2: %d\n", atoi(str2));
	//printf("MIO2: %d\n", ft_atoi(str2));
}
*/
