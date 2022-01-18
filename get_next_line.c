/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:49:48 by armendes          #+#    #+#             */
/*   Updated: 2022/01/18 18:11:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*result;
	int		len;
	int			i;
	int			j;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	j = -1;
	if (s1)
	{
		i = -1;
		while (s1[++i])
			result[++j] = s1[i];
		free((char *)s1);
	}
	i = -1;
	while (s2[++i])
		result[++j] = s2[i];
	result[++j] = '\0';
	return (result);
}

int	has_return(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*after_return(char *save)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	tmp = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!tmp)
		return (0);
	i++;
	while (save[i])
		tmp[j++] = save[i++];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

char	*before_return(char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		tmp[i] = save[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!has_return(save) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (-1);
		}
		buff[bytes_read] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	*line = before_return(save);
	save = after_return(save);
	if (bytes_read == 0)
		return (0);
	*line = ft_strjoin(*line, "\n");
	return (1);
}

char *get_next_line(int fd)
{
	char *line;
	int i;

	i = next_line(fd, &line);
	if (i == -1) 
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("Line is .%s.\n", line);
		free(line);
		i++;
	}
	return (0);
}