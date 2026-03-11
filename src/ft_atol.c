/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:18:17 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/28 01:18:07 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (sign > 0 && result > (LONG_MAX - digit) / 10)
			return (errno = ERANGE, LONG_MAX);
		if (sign < 0 && (-result) < (LONG_MIN + digit) / 10)
			return (errno = ERANGE, LONG_MIN);
		result = result * 10 + digit;
		str++;
	}
	return (sign * result);
}
