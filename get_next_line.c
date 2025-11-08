/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarid <aarid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:11:04 by aarid             #+#    #+#             */
/*   Updated: 2025/11/06 09:12:03 by aarid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Read from the file and concatenate with old reminder
// Extract the correct line
// Cleaning the buffer with correct leftover
// Return the line
char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reminder = read_and_concatenate(fd, reminder);
	if (!reminder)
		return (NULL);
	line = extract_line(reminder);
	if (!line)
	{
		free(reminder);
		reminder = NULL;
		return (NULL);
	}
	reminder = cleaning_reminder(reminder);
	return (line);
}

// Read and concatenate with old leftover
char	*read_and_concatenate(int fd, char *reminder)
{
	char		*buffer;
	ssize_t		read_bytes;

	if (!reminder)
		reminder = reminder_first_call();
	if (!reminder)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(reminder), NULL);
	read_bytes = 0;
	while (!(ft_strchr(reminder, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = 0;
		reminder = ft_strjoin(reminder, buffer);
		if (!reminder)
			return (free(buffer), NULL);
	}
	if (read_bytes < 0 || (read_bytes == 0 && ft_strlen(reminder) == 0))
		return (free(buffer), free(reminder), NULL);
	return (free(buffer), reminder);
}

// Concatenate the old lefover with the new data readed
char	*ft_strjoin(char *reminder, char *buffer)
{
	char	*new_reminder;
	int		buffer_len;
	int		reminder_len;
	int		index;
	int		jndex;

	buffer_len = ft_strlen(buffer);
	reminder_len = ft_strlen(reminder);
	new_reminder = malloc(sizeof(char) * (buffer_len + reminder_len + 1));
	if (!new_reminder)
	{
		free(reminder);
		return (NULL);
	}
	index = 0;
	jndex = 0;
	while (reminder[jndex])
		new_reminder[index++] = reminder[jndex++];
	while (*buffer)
		new_reminder[index++] = *buffer++;
	new_reminder[index] = 0;
	free(reminder);
	return (new_reminder);
}

char	*reminder_first_call(void)
{
	char	*reminder;

	reminder = malloc(1);
	if (!reminder)
		return (NULL);
	reminder[0] = 0;
	return (reminder);
}
