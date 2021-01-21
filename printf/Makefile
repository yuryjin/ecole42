# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2020/11/17 22:02:40 by zlucan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base variables for ft_printf library
# Use with 'include /path/to/libprintf.mk'
# Make sure to define L_PRINTF with the path to ft_printf first

# Where our library is located
L_PRINTF		?= .

# What our library will be called
PRINTF_NAME	:= libftprintf.a

# Variables to link and compile with ft_printf
PRINTF_LNK	:= -L $(L_PRINTF) -l ftprintf
PRINTF_INC	:= -I $(L_PRINTF)/includes
PRINTF_LIB	:= $(L_PRINTF)/$(PRINTF_NAME)

# Variables to link and compile all libraries
ifndef LIB_LNK
LIB_LNK			:=
LIB_INC			:=
endif

LIB_LNK			+= $(PRINTF_LNK)
LIB_INC			+= $(PRINTF_INC)

COMPONENTS := ./components
#$(addprefix $(COMPONENTS)/,(""))

#SRC_DIR  := $(addprefix $(COMPONENTS)/,("src"))
#INC_DIR  := $(addprefix $(COMPONENTS)/,("includes"))
#OBJ_DIR  := $(addprefix $(COMPONENTS)/,("obj"))
#TEST_DIR := $(addprefix $(COMPONENTS)/,("test"))

SRC_DIR  := ./components/src
INC_DIR  := ./components/includes
OBJ_DIR  := ./components/obj
TEST_DIR := ./components/test

# directories
#SRC_DIR  := ./src
#INC_DIR  := ./includes
#OBJ_DIR  := ./obj
#TEST_DIR := ./test

# gets/get_fbig .c

# src / obj files
SRC		:=	additional/additional.c \
			\
			gets/get_a.c gets/get_abig.c gets/get_c.c gets/get_d.c \
			gets/get_e.c gets/get_ebig.c gets/get_f.c \
			gets/get_g.c gets/get_gbig.c gets/get_i.c gets/get_n.c \
			gets/get_o.c gets/get_p.c gets/get_percent.c gets/get_s.c \
			gets/get_S.c gets/get_u.c gets/get_x.c gets/get_xbig.c \
			\
			parsing/checks.c parsing/ft_printf_parsing_gettypes.c \
			parsing/ft_printf_parsing_getvars.c parsing/ft_printf_parsing.c \
			parsing/checks2.c \
			\
			printfmain/ft_printf.c \
			\
			libft2/libft2.c \
			libft2/libft.c \
			libft2/libft3.c

OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -O3 -march=native -pipe

NAME	:= $(PRINTF_NAME)

# rules
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/additional
	@mkdir -p $(OBJ_DIR)/gets
	@mkdir -p $(OBJ_DIR)/libft2
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/printfmain

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -o $@ -c $<
	#$(CC) $(LIB_INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C ./components/libft all
	@ar rc $(PRINTF_NAME) $(OBJ) ./components/libft/ft_atoi.o ./components/libft/ft_isdigit.o \
	./components/libft/ft_itoa.o ./components/libft/ft_strlen.o ./components/libft/ft_strrev.o \
	./components/libft/ft_strdup.o ./components/libft/ft_memset.o ./components/libft/ft_putstr.o 
	@ranlib $(PRINTF_NAME)
	echo "\n*****\n\nCompiled Succesfully\n\n*****\n"

test:
	@$(MAKE) -C $(TEST_DIR) --no-print-directory

clean:
	@make -C ./components/libft clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ./components/libft fclean
	@rm -f $(PRINTF_NAME)

re:
	@make -C ./components/libft re
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all clean fclean re relibs test
