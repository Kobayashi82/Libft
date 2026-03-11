/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:02:27 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/28 16:46:30 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, int old_size, int size)
{
	void	*new_ptr;
	int		min_size;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		if (old_size < size)
			min_size = old_size;
		else
			min_size = size;
		ft_memcpy(new_ptr, ptr, min_size);
		free(ptr);
	}
	return (new_ptr);
}
