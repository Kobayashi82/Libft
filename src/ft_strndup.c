/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:13:57 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/28 16:03:35 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	len;

	if (!s1)
		return (NULL);
	len = 0;
	while (len < n && s1[len] != '\0')
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, len);
	copy[len] = '\0';
	return (copy);
}
