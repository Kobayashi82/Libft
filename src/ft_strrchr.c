/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:45:53 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/28 20:04:57 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen (s);
	s += len;
	while (len-- > 0)
	{
		if (*s == (char)c)
			break ;
		s--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
