/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:34:51 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 16:48:40 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	suppr_com(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == COMMENT_CHAR)
		{
			str[i] = 0;
			return ;
		}
		i++;
	}
}

static char	*epur_str(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = ft_memalloc((ft_strlen(str) + 10) * sizeof(char));
	init_str(s, ft_strlen(str) + 10);
	while (str && str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str && str[i])
	{
		while (str && str[i] && str[i] != ' ' && str[i] != '\t')
			s[j++] = str[i++];
		s[j++] = ' ';
		while (str && str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
	}
	ft_strdel(&str);
	return (s);
}

void		fill_file(t_file *file)
{
	char	*str;
	int		i;

	i = 0;
	while ((str = get_next_line_mod(file->fd_file)) != NULL)
	{
		suppr_com(str);
		str = epur_str(str);
		if (str)
		{
			if (ft_strlen(str) > 0)
				init_line(file, str);
			ft_strdel(&str);
		}
		i++;
	}
}
