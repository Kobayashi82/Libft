/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:25:58 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/28 01:21:23 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = 0;
	dest_len = 0;
	while (dst[dest_len] && dest_len < dstsize)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dstsize == 0 || dest_len >= dstsize)
		return (dest_len + src_len);
	i = dest_len;
	while (i < dstsize - 1 && src[i - dest_len])
	{
		dst[i] = src[i - dest_len];
		i++;
	}
	dst[i] = '\0';
	return (dest_len + src_len);
}
