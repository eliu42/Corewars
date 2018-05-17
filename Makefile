# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 18:20:10 by adubugra          #+#    #+#              #
#    Updated: 2018/05/17 01:27:14 by adubugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CWR	= corewar
ASM	= asm

# src / obj files
SRC		=	read_file.c \
			constructor.c \
			checker.c \
			print.c \
			init_ops.c \
			function_controller.c \
			conversions.c 

SRCALL	= $(SRC)
SRCALL	+= corewar.c
#SRCALL	+= assembler.c

SRCCW	= $(SRC)
SRCCW	+= corewar.c

#SRCAS	= $(SRC)
#SRCAS	+= assembler.c

OBJ	= $(addprefix $(OBJDIR),$(SRCALL:.c=.o))
OBJCW	= $(addprefix $(OBJDIR),$(SRCCW:.c=.o))
#OBJAS	= $(addprefix $(OBJDIR),$(SRCAS:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(CWR)

test: obj $(FT_LIB) $(ASM)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(CWR): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJCW) $(FT_LNK) -lm -o $(CWR)
#	$(CC) $(CFLAGS) $(OBJAS) $(FT_LNK) -lm -o $(ASM)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(CWR)
	rm -rf $(ASM)
	make -C $(FT) fclean

re: fclean all
