/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:22:47 by trcottam          #+#    #+#             */
/*   Updated: 2021/06/21 10:58:52 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft/libft.h"

# define HEX_PREFIX "0x"

typedef union u_var {
	uintmax_t	i;
	double		d;
	char		c;
	char		*s;
}	t_var;

typedef enum e_spec {
	SPEC_SDEC = 'd',
	SPEC_UDEC = 'u',
	SPEC_UHEX = 'x',
	SPEC_DSCI = 'e',
	SPEC_DDEC = 'f',
	SPEC_DAUTO = 'g',
	SPEC_CHAR = 'c',
	SPEC_STR = 's',
	SPEC_PTR = 'p',
	SPEC_LEN = 'n',
	SPEC_PERCENT = '%',
}	t_spec;

typedef enum e_len {
	LEN_CHAR = 1,
	LEN_SHORT,
	LEN_LONG,
	LEN_LLONG,
}	t_len;

typedef struct s_double_parts {
	uintmax_t	i;
	uintmax_t	d;
}	t_double_parts;

typedef struct s_double{
	t_double_parts	parts;
	size_t			dec_part_len;
	bool			sci;
	int				exp;
}	t_double;

typedef struct s_conv {
	t_spec		spec;
	t_var		var;
	char		*str;
	t_len		len;
	int			width;
	int			precision;
	bool		negative;
	bool		uppercase;
	bool		alt;
	bool		zero;
	bool		left;
	bool		space;
	bool		sign;
	bool		null_char;
}				t_conv;

int				ft_printf(const char *format, ...);
int				print_ordinary_str(char **format);
int				process_format(char *format, va_list *args);
int				print_conv(char **format, va_list *args, int written_len);
void			len_to_arg(int written_len, va_list *args, t_conv *conv);
void			print_null_char_conv(t_conv *conv);
t_conv			format_to_conv(char **format, va_list *args);
void			init_conv(t_conv *conv);
void			convert_arg(t_conv *conv, va_list *args);

void			process_flags(char **format, t_conv *conv);
void			process_width(char **format, va_list *args, t_conv *conv);
void			process_precision(char **format, va_list *args, t_conv *conv);
void			process_len(char **format, t_conv *conv);
void			process_spec(char **format, t_conv *conv);

void			arg_to_conv(va_list *args, t_conv *conv);
void			int_arg_to_conv(va_list *args, t_conv *conv);
void			double_arg_to_conv(va_list *args, t_conv *conv);
void			char_arg_to_conv(va_list *args, t_conv *conv);
void			str_arg_to_conv(va_list *args, t_conv *conv);

void			apply_precision_padding(t_conv *conv);
void			apply_zero_padding(t_conv *conv);
void			apply_prefix(t_conv *conv);
void			apply_sign(t_conv *conv);
void			apply_space_padding(t_conv *conv);
void			apply_uppercase(t_conv *conv);

bool			conv_has_sign(t_conv *conv);
bool			conv_is_int(t_conv *conv);
bool			conv_is_unsigned(t_conv *conv);
bool			conv_is_double(t_conv *conv);
bool			conv_is_sci(t_conv *conv, double d);

unsigned int	get_conv_base(t_conv *conv);
size_t			get_prefix_len(char *str, t_conv *conv);
void			int_arg_to_conv_var(va_list *args, t_conv *conv);
int				get_double_sci_power(double d, int precision);

void			init_double_s(t_double *ds);
int				get_double_conv_precision(t_conv *conv);
t_double_parts	get_double_parts(double d, int dec_part_len);
void			get_sci_double_s(double d, t_double *ds);
t_double		conv_to_double_s(t_conv *conv);
bool			double_int_part_to_conv(t_conv *conv, t_double *ds);
bool			append_double_dec_sep(t_conv *conv, t_double *ds);
bool			append_double_dec_part(t_conv *conv, t_double *ds);
bool			append_double_sci_suffix(t_conv *conv, t_double *ds);

#endif
