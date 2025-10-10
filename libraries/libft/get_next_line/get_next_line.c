/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:20:57 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/10 11:26:52 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
**
** Summary:
** • get_rest extracts the content after a newline from a line and returns it
**  as a substring.
** • fill_line reads from the file and appends the read data to line, ensuring
** that each line is built until a newline or EOF is reached.
** • get_next_line coordinates reading lines from a file, using the above
** two functions to assemble and return one line at a time.
** • main shows how to use get_next_line to read and print lines from a file.
** Each function is optimized for reading lines from a file using buffers
** and string functions like ft_strdup, ft_strjoin, and get_rest.
**
 */

static char	*left_line(char *buffer)
{
	int			i;
	char		*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0' || buffer[i] == '\0')
		return (NULL);
	line = ft_substr_gnl(buffer, i + 1, ft_strlen_gnl(buffer) - i);
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	buffer[i + 1] = '\0';
	return (line);
}

static char	*fill_line(int fd, char *buffer, char *new_line)
{
	int		read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes != '\0')
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!new_line)
			new_line = ft_strdup_gnl("");
		temp = new_line;
		new_line = ft_strjoin_gnl(temp, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (new_line);
}

// static void free_new_line(char *line)
// {
// 	if (line)
// 	{
// 		free(line);
// 		line = NULL;
// 	}
// }

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	static char		*new_line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(new_line);
		new_line = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line(fd, buffer, new_line);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	new_line = left_line(line);
	return (line);
}

/* int	main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		return (printf("error 1"));
	}
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
} */
///

/* 
#include "libft.h"

static char	*dupnewline(char *str)
{
	int		i;
	char	*newline;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newline = malloc(i + 2);
	if (!newline)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		newline[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

static char	*conc(char *stach, char *buffer)
{
	int		i;
	int		j;
	char	*ptr;
	int		stach_len;
	int		buffer_len;

	i = -1;
	j = 0;
	stach_len = ft_strlen(stach);
	buffer_len = ft_strlen(buffer);
	if (!stach || !buffer)
		return (NULL);
	ptr = malloc((stach_len + buffer_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (stach)
		while (stach[++i] != '\0')
			ptr[i] = stach[i];
	while (buffer[j] != '\0')
		ptr[i++] = buffer[j++];
	ptr[stach_len + buffer_len] = '\0';
	free(stach);
	return (ptr);
}

static char	*ft_trim(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free(str);
		return (NULL);
	}
	new_str = malloc((ft_strlen(str) - i + 1));
	if (!new_str)
		return (NULL);
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

static char	*fill_stach(int fd, char *stach)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stach, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stach);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stach = conc(stach, buffer);
		if (!stach)
			return (NULL);
	}
	free(buffer);
	return (stach);
}

char	*get_next_line(int fd)
{
	char			*newline;
	static char		*stach;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!stach)
	{
		stach = malloc(1 * sizeof(char));
		if (!stach)
			return (NULL);
		stach[0] = '\0';
	}
	stach = fill_stach(fd, stach);
	if (!stach)
		return (NULL);
	newline = dupnewline(stach);
	stach = ft_trim(stach);
	return (newline);
}

 */
