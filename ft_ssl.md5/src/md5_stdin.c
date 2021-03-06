/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 18:03:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/14 09:36:39 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	md5_stdin(void)
{
	t_vector	v;
	int			ret;
	char		buf[BUFF_SIZE];

	g_flags |= STDINREAD;
	if (ft_vector_init(&v, BUFF_SIZE) == -1)
		return ;
	while ((ret = read(STDIN_FILENO, buf, BUFF_SIZE)))
		ft_vector_nappend(&v, buf, ret);
	md5_string(v.data);
	g_flags -= STDINREAD;
	ft_vector_free(&v);
}
