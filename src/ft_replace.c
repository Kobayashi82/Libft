/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:25:58 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/28 01:21:23 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_matches(const char *str, const char *old, size_t old_len)
{
	const char	*tmp;
	size_t		count;

	count = 0;
	tmp = str;
	while (1)
	{
		tmp = ft_strstr(tmp, old);
		if (!tmp)
			break ;
		tmp += old_len;
		count++;
	}
	return (count);
}

static char	*alloc_result(const char *str, const char *old,
		const char *new, size_t count)
{
	size_t	old_len;
	size_t	new_len;
	size_t	result_len;

	old_len = ft_strlen(old);
	new_len = ft_strlen(new);
	result_len = ft_strlen(str) + (count * new_len) - (count * old_len);
	return (malloc(result_len + 1));
}

static void	fill_result(char *result, const char *str, const char *old,
		const char *new)
{
	char		*pos;
	const char	*tmp;
	size_t		old_len;
	size_t		new_len;
	size_t		len;

	old_len = ft_strlen(old);
	new_len = ft_strlen(new);
	pos = result;
	tmp = ft_strstr(str, old);
	while (tmp)
	{
		len = tmp - str;
		ft_memcpy(pos, str, len);
		pos += len;
		ft_memcpy(pos, new, new_len);
		pos += new_len;
		str = tmp + old_len;
		tmp = ft_strstr(str, old);
	}
	ft_strcpy(pos, str);
}

char	*ft_replace(const char *str, const char *old, const char *new)
{
	char	*result;
	size_t	old_len;
	size_t	count;

	if (!str || !old || !new)
		return (NULL);
	old_len = ft_strlen(old);
	if (old_len == 0)
		return (NULL);
	count = count_matches(str, old, old_len);
	if (count == 0)
		return (ft_strdup(str));
	result = alloc_result(str, old, new, count);
	if (!result)
		return (NULL);
	fill_result(result, str, old, new);
	return (result);
}
