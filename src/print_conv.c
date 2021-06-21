/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:11:49 by trcottam          #+#    #+#             */
/*   Updated: 2021/06/21 10:25:26 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conv(char **format, va_list *args, int written_len)
{
	t_conv		conv;
	int			len;

	conv = format_to_conv(format, args);
	if (conv.spec == SPEC_PERCENT)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (conv.spec == SPEC_LEN)
	{
		len_to_arg(written_len, args, &conv);
		return (0);
	}
	convert_arg(&conv, args);
	if (!conv.str)
		return (0);
	if (conv.spec == SPEC_CHAR && conv.var.c == '\0')
		print_null_char_conv(&conv);
	else
		ft_putstr_fd(conv.str, 1);
	len = ft_strlen(conv.str);
	free(conv.str);
	return (len);
}
