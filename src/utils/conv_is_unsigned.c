/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_is_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:55:40 by trcottam          #+#    #+#             */
/*   Updated: 2020/12/17 20:36:21 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	conv_is_unsigned(t_conv *conv)
{
	return (
			conv->spec == SPEC_UDEC ||
			conv->spec == SPEC_UHEX ||
			conv->spec == SPEC_PTR);
}
