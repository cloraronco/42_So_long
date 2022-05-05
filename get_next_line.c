/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:10:02 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/28 15:37:38 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_text(int fd, char *buffer, char *temp)
{
	int		ret;
	char	*temp_dest;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		else if (ret == 0)
			return (temp);
		buffer[ret] = '\0';
		if (!temp)
			temp = ft_strdup("");
		temp_dest = temp;
		temp = ft_strjoin(temp_dest, buffer);
		free (temp_dest);
		if (!temp)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			return (temp);
	}
	return (temp);
}

char	*get_str(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i] || !line[1])
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!temp[0])
	{
		free (temp);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_text(fd, buffer, temp);
	free(buffer);
	if (!line)
		return (NULL);
	temp = get_str(line);
	return (line);
}
