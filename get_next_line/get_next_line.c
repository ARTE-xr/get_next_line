/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:46:21 by mattif            #+#    #+#             */
/*   Updated: 2021/12/19 01:16:09 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buff(int fd, char *rs)
{
	int		s;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	s = 1;
	while (s && !ft_strchr(rs, '\n'))
	{
		s = read(fd, buff, BUFFER_SIZE);
		if (s == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[s] = '\0';
		rs = ft_strjoin(rs, buff);
	}
	free(buff);
	return (rs);
}

char	*get_new_line(char *rs)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	if (!rs[i])
		return (NULL);
	while (rs[i] != '\n' && rs[i])
		i++;
	len = i + 1;
	if (rs[i] == '\n')
		len++;
	line = (char *)malloc(len);
	if (!line)
		return (NULL);
	i = 0; 
	while (rs[i] && rs[i] != '\n')
	{
		line[i] = rs[i];
		i++;
	}
	if (rs[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_new_res(char *rs)
{
	int		i;
	int		x;
	char	*rst;

	i = 0;
	while (rs[i] != '\0' && rs[i] != '\n')
		i++;
	if (!rs[i])
	{
		free(rs);
		return (NULL);
	}
	i++;
	x = ft_strlen(&rs[i]);
	rst = (char *)malloc(x + 1);
	if (!rst)
		return (NULL);
	x = 0;
	while (rs[i])
		rst[x++] = rs[i++];
	rst[x] = '\0';
	free(rs);
	return (rst);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = read_buff(fd, res);
	if (!res)
		return (NULL);
	line = get_new_line(res);
	res = get_new_res(res);
	return (line);
}
int main()
{
	int i;
	i = 0;
	
		printf("%s", get_next_line(0));
}