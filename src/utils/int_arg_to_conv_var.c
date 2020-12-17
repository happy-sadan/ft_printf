/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg_to_conv_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:32:31 by trcottam          #+#    #+#             */
/*   Updated: 2020/12/17 21:39:31 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_arg_to_conv_var(va_list *args, t_conv *conv)
{
	if (conv->spec == SPEC_SDEC)
	{
		if (conv->len == LEN_LONG)
			conv->var.i = va_arg(*args, long int);
		else if (conv->len == LEN_LLONG)
			conv->var.i = va_arg(*args, long long int);
		else
			conv->var.i = va_arg(*args, int);
	}
	else
	{
		if (conv->spec == SPEC_PTR)
			conv->var.i = (uintptr_t)va_arg(*args, void *);
		else if (conv->len == LEN_LONG)
			conv->var.i = va_arg(*args, unsigned long int);
		else if (conv->len == LEN_LLONG)
			conv->var.i = va_arg(*args, unsigned long long int);
		else
			conv->var.i = va_arg(*args, unsigned int);
	}
}
