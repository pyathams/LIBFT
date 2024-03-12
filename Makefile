# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 11:57:08 by pyathams          #+#    #+#              #
#    Updated: 2024/03/12 16:19:46 by pyathams         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of my program.
NAME	= libft.a

# The source files.
SRC		=	ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_strlcat.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_calloc.c \
			ft_substr.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_putnbr_fd.c \

SRCB	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			
# The flags to compile the c files with			
CFLAGS	= -Wall -Wextra -Werror

# The object files for mandatory part.
OBJM	= $(SRC:.c=.o)

# The object files for BONUS part.
OBJB	= $(SRCB:.c=.o)

# Variables
CC		= cc
RM		= rm -f

#rule for c and o files 
%.o : %.c
	${CC} ${CFLAGS} -g -c $*.c -o $*.o

#compiles the mandatory part of the library.
${NAME}: ${OBJM}
	ar rcs ${NAME} ${OBJM}
	
all: ${NAME}

#CLEANING FILE WHEN IT CALLED 
clean:
	${RM} ${OBJM} ${OBJB}
#FORCECLEAN INCLUDING THE NAME
fclean:	clean
	${RM} ${NAME}

#Recompiling everything
re:	fclean all

bonus :	${OBJB}
	ar rcs ${NAME} ${OBJB}