/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:09:26 by ryagoub           #+#    #+#             */
/*   Updated: 2023/12/11 14:48:22 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_line(char *line, char *word)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(line, word);
	if (!line)
		return (free(word), NULL);
	free(tmp);
	free(word);
	return (line);
}

char	*get_lines(char *line, int fd)
{
	char	*word;
	int		b;

	b = 1;
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	while (b != 0)
	{
		word = (char *) malloc (sizeof(char) * (BUFFER_SIZE +1));
		if (!word)
			return (free (line), NULL);
		b = read(fd, word, BUFFER_SIZE);
		if (b == -1)
			return (free(word), free(line), NULL);
		if (b == 0)
			return (free(word), line);
		word[b] = '\0';
		line = join_line(line, word);
		if (!line)
			return (NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

size_t	line_length(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line [i] == '\n')
		return (i + 1);
	return (i);
}

int	exclude_line(char *s_line, char *line)
{
	int	i;

	i = 0;
	while (s_line[i] != '\n' && s_line[i])
	{
		line[i] = s_line[i];
		i++;
	}
	if (s_line[i] == '\n')
		line[i++] = '\n';
	line [i] = '\0';
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*s_line[1024];
	char		*line;
	int			i;
	char		*tmp;

	i = 0;
	if ((fd < 0) || (fd >= 1024))
		return (NULL);
	s_line[fd] = get_lines(s_line[fd], fd);
	if (!s_line[fd])
		return (NULL);
	if (s_line[fd][0] == '\0')
		return (free(s_line[fd]), s_line[fd] = NULL, NULL);
	line = (char *) malloc (sizeof(char) * (line_length(s_line[fd]) + 1));
	if (!line)
	{
		free(s_line[fd]);
		return (s_line[fd] = NULL, NULL);
	}
	i = exclude_line(s_line[fd], line);
	tmp = s_line[fd];
	s_line[fd] = ft_strdup(tmp + i);
	return (free(tmp), line);
}
