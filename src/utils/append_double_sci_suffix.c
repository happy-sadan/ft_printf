/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_double_sci_suffix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:10:57 by trcottam          #+#    #+#             */
/*   Updated: 2021/06/21 10:30:30 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	append_double_sci_suffix(t_conv *conv, t_double *ds)
{
	char	*power_str;

	if (!ds->sci)
		return (true);
	if (!(
			ft_strappend(&conv->str, "e")
			&& ft_strappend(&conv->str, ds->exp >= 0 ? "+" : "-")))
		return (false);
	power_str = ft_itoa(ft_abs(ds->exp));
	if (!(
			power_str
			&& ft_strpad(&power_str, '0', 2, 0)
			&& ft_strappend(&conv->str, power_str)))
		return (false);
	free(power_str);
	return (true);
}
