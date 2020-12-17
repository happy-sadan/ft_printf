/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_to_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:58:33 by trcottam          #+#    #+#             */
/*   Updated: 2020/12/17 16:31:52 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	format_to_conv(char **format, va_list *args)
{
	t_conv conv;

	(*format)++;
	init_conv(&conv);
	process_flags(format, &conv);
	process_width(format, args, &conv);
	process_precision(format, args, &conv);
	process_len(format, &conv);
	process_spec(format, &conv);
	return (conv);
}
