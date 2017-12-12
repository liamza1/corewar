/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd_in_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:36:41 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 17:15:07 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	count_case_tab(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == SEPARATOR_CHAR || str[i] == '\t')
			count++;
		i++;
	}
	return (count);
}

char		**put_cmd_in_list(char *s)
{
	int		i;
	int		j;
	int		word;
	char	**cmd;

	i = 0;
	j = 0;
	word = count_case_tab(s);
	cmd = ft_memalloc(sizeof(char *) * (word + 5));
	word = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == SEPARATOR_CHAR || s[i] == '\t'))
			i++;
		cmd[j] = ft_memalloc(sizeof(char) * (ft_strlen(s) + 5));
		while (s[i] && (s[i] != ' ' && s[i] != SEPARATOR_CHAR && s[i] != '\t'))
			cmd[j][word++] = s[i++];
		cmd[j][word++] = '\0';
		while (s[i] && (s[i] == ' ' || s[i] == SEPARATOR_CHAR || s[i] == '\t'))
			i++;
		word = 0;
		j++;
	}
	cmd[j] = NULL;
	return (cmd);
}

t_op		*find_struct(char *str)
{
	int		i;

	i = 0;
	while ((&g_op_tab[i])->code != 0)
	{
		if ((ft_match(str, (&g_op_tab[i])->mnemonique)) == 1)
			return (&g_op_tab[i]);
		i++;
	}
	return (NULL);
}
