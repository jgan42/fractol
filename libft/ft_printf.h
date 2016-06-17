/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 17:17:38 by jgan              #+#    #+#             */
/*   Updated: 2015/11/20 19:19:10 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_info
{
	int		nb_print;
	int		posn;
	int		w_min;
	int		prec;
	char	conv;
	char	*flag;
	char	lenmod;
}				t_info;
int				ft_printf(char *form, ...);
int				is_conv(char c);
int				is_flag(char c);
int				is_lenmod(char c);
int				check_format(char *s);
t_info			*init_info(void);
void			get_info(char *s, va_list va, t_info *info);
int				get_w_min(char *s, va_list va, t_info *info, int i);
int				get_prec(char *s, va_list va, t_info *info, int i);
int				get_lenmod(char *s, t_info *info, int i);
void			print_int(va_list va, t_info *info);
void			print_char(va_list va, t_info *info);
void			print_str(va_list va, t_info *info);
void			print_uint(va_list va, t_info *info);
void			print_float(va_list va, t_info *info);
void			disp_int(unsigned long long aff, long long i, t_info *info);
void			ft_putnbr_ull(unsigned long long int n, t_info *info);
char			*get_unicode(int c);
void			print_wchar(int c, t_info *info);
void			print_wstr(va_list va, t_info *info);
int				wcharlen(wchar_t c);
int				wstrlen(wchar_t *s);
int				nbrlen(unsigned long long int n, t_info *info);
void			fill_prec(unsigned long long int aff, t_info *info);
int				wdisplen(wchar_t *s, t_info *info);
#endif
