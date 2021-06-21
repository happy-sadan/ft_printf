/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arg_to_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:13:00 by trcottam          #+#    #+#             */
/*   Updated: 2021/06/21 10:24:35 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_arg_to_conv(va_list *args, t_conv *conv)
{
	conv->var.s = va_arg(*args, char *);
	if (conv->var.s)
		conv->str = ft_strdup(conv->var.s);
	else if (conv->precision >= 6 || conv->precision == -1)
		conv->str = ft_strdup("(null)");
	else
		conv->str = ft_strdup("");
	if (conv->precision != -1
		&& conv->var.s
		&& conv->precision < (int)ft_strlen(conv->str))
		conv->str[conv->precision] = '\0';
}
