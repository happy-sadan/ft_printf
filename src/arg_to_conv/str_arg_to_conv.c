/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arg_to_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:13:00 by trcottam          #+#    #+#             */
/*   Updated: 2020/12/17 16:18:10 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_arg_to_conv(va_list *args, t_conv *conv)
{
	conv->var.s = va_arg(*args, char *);
	conv->str = ft_strdup(conv->var.s);
	if (conv->precision != -1 && conv->precision < (int)ft_strlen(conv->var.s))
		conv->str[conv->precision] = '\0';
}
