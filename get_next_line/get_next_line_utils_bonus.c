/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:10:19 by ryagoub           #+#    #+#             */
/*   Updated: 2023/12/10 21:29:07 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return (str + i);
		}
		i++;
	}
	if (str[i] == (char)c)
	{
		return (str + i);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
	{
		return (NULL);
	}
	else
	{
		ft_strlcpy (dest, s1, ft_strlen (s1) + 1);
		return (dest);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = (char *)malloc (sizeof(char) * (ft_strlen(s1)+ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	while (s2[j] != '\0')
		str[k++] = s2[j++];
	str[k] = '\0';
	return (str);
}
