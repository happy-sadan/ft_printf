# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 13:54:47 by trcottam          #+#    #+#              #
#    Updated: 2020/12/17 22:11:30 by trcottam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c\
		print_ordinary_str.c\
		process_format.c\
		print_conv.c\
		len_to_arg.c\
		print_null_char_conv.c\
		format_to_conv.c\
		convert_arg.c\
		init_conv.c\
		processors/process_flags.c\
		processors/process_width.c\
		processors/process_precision.c\
		processors/process_len.c\
		processors/process_spec.c\
		arg_to_conv/arg_to_conv.c\
		arg_to_conv/int_arg_to_conv.c\
		arg_to_conv/double_arg_to_conv.c\
		arg_to_conv/char_arg_to_conv.c\
		arg_to_conv/str_arg_to_conv.c\
		appliers/apply_precision_padding.c\
		appliers/apply_zero_padding.c\
		appliers/apply_prefix.c\
		appliers/apply_sign.c\
		appliers/apply_space_padding.c\
		appliers/apply_uppercase.c\
		utils/conv_has_sign.c\
		utils/get_conv_base.c\
		utils/conv_is_unsigned.c\
		utils/conv_is_int.c\
		utils/conv_is_double.c\
		utils/get_prefix_len.c\
		utils/conv_is_sci.c\
		utils/int_arg_to_conv_var.c\
		\
		utils/init_double_s.c\
		utils/get_double_conv_precision.c\
		utils/get_double_parts.c\
		utils/get_sci_double_s.c\
		utils/conv_to_double_s.c\
		utils/double_int_part_to_conv.c\
		utils/append_double_dec_sep.c\
		utils/append_double_dec_part.c\
		utils/append_double_sci_suffix.c\

OBJ = $(SRC:%=$(OBJ_DIR)/%.o)

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = .

MAKE = make
MKDIR = mkdir -p
MV = mv
RM = rm -fr
AR = ar rcs

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

.PHONY:		all bonus clean fclean re test

.SECONDEXPANSION:

all bonus: $(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C libft
	$(MV) libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJ_DIR)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

test:		bonus
	$(CC) test.c $(CFLAGS) -L. -lftprintf

%/:
	$(MKDIR) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/% | $$(dir $(OBJ_DIR)/%)
	$(CC) $(CFLAGS) -c -o $@ $<
