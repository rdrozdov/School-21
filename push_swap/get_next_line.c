/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:54:49 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 13:29:05 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*my_read(char *reminder, int fd)
{
	int		byte_was_read;
	char	*buf;

	byte_was_read = 1;
	buf = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (byte_was_read && !ft_strchr(reminder, '\n'))
	{
		byte_was_read = read (fd, buf, BUFFER_SIZE);
		if (byte_was_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_was_read] = '\0';
		reminder = ft_strjoin(reminder, buf);
	}
	free(buf);
	return (reminder);
}

static char	*get_result(char *reminder)
{
	int		counter;
	char	*buf;

	if (reminder == NULL)
		return (NULL);
	counter = 0;
	if (reminder[0] == '\0')
		return (NULL);
	while (reminder[counter] != '\n' && reminder[counter] != '\0')
		counter++;
	if (reminder[counter] == '\n')
		counter++;
	buf = ft_substr(reminder, 0, counter);
	return (buf);
}

static char	*get_reminder(char *reminder)
{
	char	*buf;
	int		counter;

	if (reminder == NULL)
		return (NULL);
	counter = 0;
	while (reminder[counter] != '\n' && reminder[counter] != '\0')
		counter++;
	if (reminder[counter] == '\n')
		counter++;
	if (reminder[0] == '\0')
	{
		free(reminder);
		return (NULL);
	}
	buf = ft_substr(reminder, counter, (ft_strlen(reminder) - counter));
	free(reminder);
	return (buf);
}

char	*get_next_line(int fd, char **line)
{
	static char	*reminder;
	char		*result;

	result = *line;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	reminder = my_read(reminder, fd);
	*line = get_result(reminder);
	reminder = get_reminder(reminder);
	free(result);
	return (*line);
}
