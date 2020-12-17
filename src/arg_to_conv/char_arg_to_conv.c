/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_arg_to_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:32:14 by trcottam          #+#    #+#             */
/*   Updated: 2020/12/09 15:51:52 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_arg_to_conv(va_list *args, t_conv *conv)
{
	conv->var.c = va_arg(*args, int);
	conv->str = ft_strdup(ft_chartostr(conv->var.c));
}
