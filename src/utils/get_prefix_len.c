/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prefix_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 01:02:42 by trcottam          #+#    #+#             */
/*   Updated: 2020/12/06 21:50:11 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_prefix_len(char *str, t_conv *conv)
{
	if (
			(conv->spec == SPEC_UHEX && conv->alt) ||
			conv->spec == SPEC_PTR)
	{
		while (*str && *str == '0')
			str++;
		if (!*str)
			return (0);
		return (ft_strlen(HEX_PREFIX));
	}
	return (0);
}
