/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:34:15 by lstreak           #+#    #+#             */
/*   Updated: 2017/10/01 17:43:57 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			generate_filename(t_file *file)
{
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	j = 0;
	file->new_file =
		ft_memalloc((ft_strlen(file->filename) + 10) * sizeof(char));
	while (file->filename[i] && file->filename[i] != '.')
		file->new_file[j++] = file->filename[i++];
	file->new_file[j] = '\0';
	tmp = ft_strdup(file->filename);
	file->new_file = concat(tmp, ".cor");
	ft_strdel(&tmp);
}

void			write_a(t_file *file, int fd)
{
	t_line		*tmp;
	t_cmd		*tmp2;
	char		put;

	tmp = file->lines;
	while (tmp)
	{
		tmp2 = tmp->line_final;
		if (tmp2 != NULL)
		{
			while (tmp2)
			{
				put = (char)tmp2->nb;
				if (write(fd, &put, 1) == -1)
					ft_putstr("asm: Error on write\n");
				tmp2 = tmp2->next;
			}
		}
		tmp = tmp->next;
	}
}

void			read_to_list(t_file *file)
{
	int			rights;
	int			fd;
	int			type;

	generate_filename(file);
	rights = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH;
	type = O_CREAT | O_RDWR | O_TRUNC;
	fd = open(file->new_file, type, rights, 0644);
	if (fd != -1)
	{
		write_header(file, fd);
		write_a(file, fd);
	}
	else
		ft_putstr("asm: File not created\n");
}

void			generate_fixed_label(t_file *file, t_line *list)
{
	if ((list->cmd) && (list->cmd[0]))
	{
		if (is_label(list->cmd[0]) == 1)
		{
			verif_lbl_char(list->cmd[0]);
			init_label(file, list->cmd[0]);
		}
	}
}

void			ft_asm(char *str)
{
	t_file		*file;

	file = ft_memalloc(sizeof(t_file));
	init_file(file, str);
	file->header = ft_memalloc(sizeof(t_header));
	init_header(file->header);
	fill_file(file);
	parse(file);
	read_to_list(file);
	ft_putstr("Compiling ");
	ft_putendl(file->new_file);
	ft_putstr("... DONE.\n");
	free_all(file);
}
