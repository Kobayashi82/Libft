/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:55:10 by vzurera-          #+#    #+#             */
/*   Updated: 2026/03/11 18:41:37 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *v1, const char *v2, int md)
{
	char	*new_str;
	int		len;

	if (!v1 && !v2)
		return (NULL);
	len = ft_strlen(v1) + ft_strlen(v2) + 1;
	new_str = malloc(len);
	if (new_str)
	{
		if (v1)
		{
			ft_strlcpy(new_str, v1, len);
			if (v2)
				ft_strlcat(new_str, v2, len);
		}
		else if (v2)
			ft_strcpy(new_str, v2);
	}
	if (md == 1 || md == 3)
		free((void *)v1);
	if (md == 2 || md == 3)
		free((void *)v2);
	return (new_str);
}

char	*ft_strjoin_sep(const char *v1, const char *v2,	const char *v3, int md)
{
	char	*new_str;
	int		len;

	len = ft_strlen(v1) + ft_strlen(v2) + ft_strlen(v3);
	if (!v1 && !v2 && !v3)
		return (NULL);
	new_str = malloc(len + 1);
	if (new_str) {
		if (v1)
		{
			ft_strlcpy(new_str, v1, len + 1);
			if (v2)
				ft_strlcat(new_str, v2, len + 1);
			if (v3)
				ft_strlcat(new_str, v3, len + 1);
		}
		else if (v2)
		{
			ft_strlcpy(new_str, v2, len + 1);
			if (v3)
				ft_strlcat(new_str, v3, len + 1);
		}
		else if (v3)
			ft_strlcpy(new_str, v3, len + 1);
	}
	if (v1 && (md == 1|| md == 4 || md == 6 || md == 7))
		free((void *)v1);
	if (v2 && (md == 2 || md == 4 || md == 5 || md == 7))
		free((void *)v2);
	if (v3 && (md == 3 || md == 6 || md == 5 || md == 7))
		free((void *)v3);
	return (new_str);
}
