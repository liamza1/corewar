/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:36:48 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 17:17:09 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char			*concat(char *str1, char *str2)
{
	char		*ret;
	int			size;
	int			i;
	int			j;

	i = 0;
	j = 0;
	size = ft_strlen(str1) + ft_strlen(str2) + 5;
	ret = ft_memalloc(size * sizeof(char));
	str1 = ft_strrchr(str1, '/') + 1;
	while (str1 && str1[i + 2])
		ret[j++] = str1[i++];
	i = 0;
	while (str2 && str2[i])
		ret[j++] = str2[i++];
	ret[j] = '\0';
	return (ret);
}

int				ft_pow(int nb, int pow)
{
	int			p;
	int			result;

	p = 1;
	result = 1;
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	while (p <= pow)
	{
		result = result * nb;
		p = p + 1;
	}
	return (result);
}

int				ft_match(char *str1, char *str2)
{
	int			i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == 0 && str2[i] == 0)
		return (1);
	else
		return (0);
}

static int		ft_read(int fd, char *buffer, int size)
{
	int			ret;

	ret = read(fd, buffer, size);
	if (ret == -1)
		ft_putstr("Error on read\n");
	return (ret);
}

char			*get_next_line_mod(int fd)
{
	static int	a;
	int			j;
	char		*s;
	static int	cpt = BUFFER_SIZE;
	static char	buff[BUFFER_SIZE];

	a = 1;
	s = 0;
	j = 0;
	if (cpt >= (BUFFER_SIZE - 1) && a)
	{
		cpt = 0;
		a = ft_read(fd, buff, BUFFER_SIZE - 1);
		buff[a] = '\0';
	}
	if (buff[cpt] && cpt < BUFFER_SIZE)
	{
		s = ft_memalloc(BUFFER_SIZE * sizeof(char));
		while (buff[cpt] != '\n' && buff[cpt])
			s[j++] = buff[cpt++];
		s[j] = '\0';
		if (buff[cpt])
			cpt++;
	}
	return (s);
}
