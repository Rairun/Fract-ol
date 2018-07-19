/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:17:22 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/07 11:24:07 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_list	*store;
	char			*buff;
	t_list			*curr;
	int				len;

	if (fd < 0 || line == NULL || !(buff = ft_strnew(BUFF_SIZE))
		|| read(fd, buff, 0) < 0)
		return (-1);
	curr = get_current_file(fd, &store);
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		if (put_in_store((char **)(&(curr->content)), &buff) == 0)
			return (-1);
		if (ft_strchr_n(buff, '\n') != -1)
			break ;
	}
	if (len == 0 && ft_strlen(curr->content) == 0)
		return (0);
	if (copy_before((char **)(&(curr->content)), line, '\n') == 0)
		return (-1);
	ft_strdel(&buff);
	return (1);
}

t_list	*get_current_file(int fd, t_list **store)
{
	t_list	*curr;

	curr = *store;
	while (curr)
	{
		if (curr->content_size == (size_t)fd)
			return (curr);
		curr = curr->next;
	}
	curr = ft_lstnew("\0", 1);
	curr->content_size = fd;
	ft_lstadd(store, curr);
	return (curr);
}

int		put_in_store(char **store, char **buff)
{
	char	*temple;

	temple = *store;
	if ((*store = ft_strjoin(*store, *buff)) == NULL)
		return (0);
	ft_strdel(&temple);
	ft_strclr(*buff);
	return (1);
}

int		ft_strchr_n(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

int		copy_before(char **store, char **line, char c)
{
	char	*temple;
	int		i;

	if ((i = ft_strchr_n(*store, c)) == -1)
		i = ft_strlen(*store);
	if ((*line = ft_strnew(i + 1)) == NULL)
		return (0);
	ft_strncpy(*line, *store, i);
	if ((temple = ft_strnew(ft_strlen(*store) - i + 1)) == NULL)
		return (0);
	ft_strcpy(temple, *store + i + 1);
	ft_strdel(store);
	*store = temple;
	return (1);
}
