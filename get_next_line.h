/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarid <aarid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:11:11 by aarid             #+#    #+#             */
/*   Updated: 2025/11/06 09:12:03 by aarid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_and_concatenate(int fd, char *reminder);
char	*extract_line(char *buffer);
char	*cleaning_reminder(char *reminder);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char newline);
char	*ft_strjoin(char *reminder, char *buffer);
char	*reminder_first_call(void);

#endif
