/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 22:22:58 by pbondoer          #+#    #+#             */
/*   Updated: 2020/12/09 21:44:32 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stddef.h>
# include "math.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define PF_FLAG_NONE 0
# define PF_FLAG_HASH 1
# define PF_FLAG_ZERO 2
# define PF_FLAG_MINUS 4
# define PF_FLAG_PLUS 8
# define PF_FLAG_SPACE 16
# define PF_FLAG_APOSTROPHE 32

/*
**%[флаги][ширина][.точность][размер]тип
*/

typedef enum	e_pf_modifier
{
	NONE = 0, L = 1, H = 2, J = 3, Z = 4, LL = 5, HH = 6
}				t_pf_modifier;

typedef struct	s_pf_argums
{
	int				flags;
	int				width;
	int				precision;
	t_pf_modifier	modifier;
	char			type;
	int				outputlen;
	int				dotisused;
}				t_pf_argums;

typedef int		(*t_f_vaargs)(t_pf_argums *arguments, va_list list);

typedef struct	s_pf_types
{
	char			lilletter;
	char			bigletter;
	t_f_vaargs		typing1;
	t_f_vaargs		typing2;
}				t_pf_types;

char			*dissect_float2(double n, int decimal_width);
int				pf_parse_format(const char *str, va_list list);
int				ft_printf(const char *format, ...);

/*
**parsemain
*/

int				parsemain(const char *str, size_t i, va_list list,
						t_pf_argums *arguments);
char			*ft_strchr(const char *s, int c);

/*
**checks
*/

int				ft_is_valid2(const char c);
int				ft_is_not_type(const char c);
int				ft_is_type(const char c);

int				ft_is_conversion(const char c);
int				ft_is_modifier(const char c);
int				ft_is_flag(const char c);
int				ft_is_precision(const char c);
int				ft_is_valid(const char c);

int				ft_is_valid_not_conversion(const char c);

/*
**parsing
*/

int				getmodifier(const char *str, size_t i, t_pf_argums *arguments);
int				getprecision(const char *str, size_t i, t_pf_argums *arguments,
							va_list list);
int				getwidth(const char *str, size_t i,
						t_pf_argums *arguments, va_list list);
int				getflag(const char *str, size_t i, t_pf_argums *arguments);

int				gettypes(const char *str, size_t i,
						t_pf_argums *arguments, va_list list);

int				getss(t_pf_argums *arguments, va_list list);

int				get_d(t_pf_argums *arguments, va_list list);
int				get_o(t_pf_argums *arguments, va_list list);
int				get_x(t_pf_argums *arguments, va_list list);
int				get_f(t_pf_argums *arguments, va_list list);
/*
**int get_fbig(t_pf_argums *arguments, va_list list);
**int get_gbig(t_pf_argums *arguments, va_list list);
**int get_sbig(t_pf_argums *arguments, va_list list);
*/
int				get_e(t_pf_argums *arguments, va_list list);
int				get_g(t_pf_argums *arguments, va_list list);
int				get_a(t_pf_argums *arguments, va_list list);
int				get_c(t_pf_argums *arguments, va_list list);
int				get_s(t_pf_argums *arguments, va_list list);
int				get_p(t_pf_argums *arguments, va_list list);
int				get_i(t_pf_argums *arguments, va_list list);
int				get_u(t_pf_argums *arguments, va_list list);
int				get_xbig(t_pf_argums *arguments, va_list list);
int				get_ebig(t_pf_argums *arguments, va_list list);
int				get_abig(t_pf_argums *arguments, va_list list);
int				get_percent(t_pf_argums *arguments);
int				get_n(t_pf_argums *arguments, va_list list);

/*
**additional
*/

char			*ft_strchr(const char *s, int c);

int				printf_s(t_pf_argums *arguments, char *printval);
int				printso(t_pf_argums *arguments, char *xvaluestr);
char			*dtox(intmax_t i);
char			*dtoxbig(intmax_t i);

double			ft_topower(int num, int pow);

int				ft_atoi2(const char *str);
int				ft_isdigit2(int c);
char			*ft_itoa2(intmax_t n);
size_t			ft_strlen2(const char *s);
char			*ft_strrev2(char *str);
size_t			ft_nbrlen_ull(unsigned long long n);
char			*ft_itoa_ull(unsigned long long n);

size_t			ft_nbrlen_ll(long long n);
char			*ft_itoa_ll(long long n);

int				ft_max(int *tab, int length);

int				ft_atoi2(const char *str);
int				ft_isdigit2(int c);
size_t			ft_nbrlen_ull(unsigned long long n);
char			*ft_itoa_ull(unsigned long long n);
/*
**static		size_t	ft_nbrlen2(intmax_t n);
*/

char			*ft_itoa2(intmax_t n);
size_t			ft_strlen2(const char *s);
char			*ft_strrev2(char *str);
double			ft_topower2(int num, int pow);

#endif
