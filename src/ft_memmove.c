/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:09:31 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/28 20:37:38 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!d && !s && len)
		return (dst);
	if (d < s)
		while (len-- > 0)
			*d++ = *s++;
	else
	{
		d += len - 1;
		s += len - 1;
		while (len-- > 0)
			*d-- = *s--;
	}
	return (dst);
}
