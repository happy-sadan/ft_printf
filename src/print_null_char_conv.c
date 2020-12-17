/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null_char_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:50:46 by trcottam          #+#    #+#             */
/*   Updated: 2020/12/09 13:14:00 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_null_char_conv(t_conv *conv)
{
	conv->str[ft_strlen(conv->str) - 1] = '\0';
	if (conv->left)
		ft_putchar_fd('\0', 1);
	ft_putstr_fd(conv->str, 1);
	if (!conv->left)
		ft_putchar_fd('\0', 1);
}
