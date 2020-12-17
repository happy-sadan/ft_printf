/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_is_sci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:21:57 by trcottam          #+#    #+#             */
/*   Updated: 2020/12/17 20:35:47 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	conv_is_sci(t_conv *conv, double d)
{
	int	precision;
	int	dec_cnt;
	int	power;

	if (conv->spec == SPEC_DSCI)
		return (true);
	if (conv->spec == SPEC_DDEC)
		return (false);
	precision = conv->precision >= 0 ? conv->precision : 6;
	if (precision == 0)
		precision = 1;
	dec_cnt = precision - 1;
	power = get_double_sci_power(d, dec_cnt);
	if (power < -4 || power >= precision)
		return (true);
	return (false);
}
