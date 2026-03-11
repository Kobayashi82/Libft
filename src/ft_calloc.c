/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:02:27 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/28 16:46:30 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*nuller;
	int		n;

	n = count * size - 1;
	nuller = (char *)malloc(count * size);
	if (!nuller)
		return (NULL);
	while (n >= 0)
		nuller[n--] = '\0';
	return ((void *)nuller);
}
