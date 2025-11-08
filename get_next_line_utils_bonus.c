/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarid <aarid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:10:42 by aarid             #+#    #+#             */
/*   Updated: 2025/11/06 09:12:03 by aarid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Extract the line from the buffer.
char	*extract_line(char *reminder)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (reminder[len] && reminder[len] != '\n')
		len++;
	if (reminder[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = reminder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// Cleaning the leftover reminder after extracting the line
char	*cleaning_reminder(char *reminder)
{
	char	*cleaned_reminder;
	int		left_over;
	int		index;
	int		leftover_len;

	left_over = 0;
	while (reminder[left_over] && reminder[left_over] != '\n')
		left_over++;
	if (reminder[left_over] == '\n')
		left_over++;
	leftover_len = ft_strlen(reminder) - left_over;
	cleaned_reminder = malloc(sizeof(char) * (leftover_len + 1));
	if (!cleaned_reminder)
	{
		free(reminder);
		return (NULL);
	}
	index = 0;
	while (reminder[left_over])
		cleaned_reminder[index++] = reminder[left_over++];
	cleaned_reminder[index] = 0;
	free(reminder);
	return (cleaned_reminder);
}

// Calcule length
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

// Check if the reminder has the newline
int	ft_strchr(char *str, char newline)
{
	while (*str)
	{
		if (*str == newline)
			return (1);
		str++;
	}
	return (0);
}
