/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <tmaske@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:32:12 by tmaske            #+#    #+#             */
/*   Updated: 2017/09/29 17:50:46 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../../libft/libft.h"
# include "./op.h"

typedef struct		s_label
{
	int				counter;
	char			*label;
	struct s_label	*next;
}					t_label;

typedef struct		s_cmd
{
	int				nb;
	int				label_counter;
	char			*label;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_line
{
	char			*line;
	char			**cmd;
	t_cmd			*line_final;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_file
{
	char			*filename;
	char			*new_file;
	int				fd_file;
	t_line			*lines;
	t_label			*label;
	int				counter;
	t_header		*header;
}					t_file;

# define BUFFER_SIZE 4096

void				generate_filename(t_file *file);
void				write_a(t_file *file, int fd);
void				read_to_list(t_file *file);
void				generate_fixed_label(t_file *file, t_line *list);
void				ft_asm(char *str);

void				init_file(t_file *file, char *str);
void				init_line(t_file *file, char *line);
void				init_label(t_file *file, char *label);
void				init_str(char *str, int size);
void				init_header(t_header *head);

int					is_to_parse(t_line *list);
void				verify_params_type(t_line *list, int line, t_op *ope);
void				verify_params(t_line *list, int line, t_op *ope);
void				parse(t_file *file);

int					bin_to_int(char *str);
void				des_param(t_file *file, t_line *list, int line, t_op *ope);

int					is_label(char *str);
int					is_index_func(char *str);
void				verif_lbl_char(char *str);

void				fill_file(t_file *file);

char				**put_cmd_in_list(char *s);

void				write_header(t_file *file, int fd);

int					byte_size(t_line *list, char *str, t_file *file);
int					fill_nb_in_list(t_line *list, t_file *file);
void				fill_label(t_file *file);

void				free_all(t_file *file);

void				init_cmd(t_line *list, int nb, int lbl, char *str);
t_op				*opcode(t_file *file, t_line *list, int i);
int					len_list(t_cmd *list);
int					handle_label(t_line *list, char *str, t_file *file);

int					detect_label_in_str(char *str);
void				putchar_int(t_line *list, int nb, int size, t_file *file);
int					handle_reg(t_line *list, char *str, t_file *file);
int					handle_dir(t_line *list, char *str, t_file *file);
int					handle_ind(t_line *list, char *str, t_file *file);
int					handle_ldi(t_line *list, char **str, t_file *file, int i);
int					handle_sti(t_line *list, char **str, t_file *file, int i);
int					handle_lbl(t_line *list, char *str, t_file *file);
int					hndl_frk_zjp(t_line *list, char **str, t_file *file, int i);

char				*concat(char *str1, char *str2);
int					ft_pow(int nb, int pow);
int					ft_match(char *str1, char *str2);
char				*get_next_line_mod(int fd);
int					beg_match(char *str1, char *str2);
int					convert_int(int i);
t_op				*find_struct(char *str);
int					ft_getnbr(char *str);
void				asm_error(char *type, int line);

#endif
