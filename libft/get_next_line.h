/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:17:30 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/11 13:49:52 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 200

# include "libft.h"

int		get_next_line(const int fd, char **line);
t_list	*get_current_file(int fd, t_list **store);
int		put_in_store(char **store, char **buff);
int		ft_strchr_n(const char *s, int c);
int		copy_before(char **store, char **line, char c);

#endif
