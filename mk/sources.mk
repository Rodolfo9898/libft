# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/07 00:00:00 by rperez-t          #+#    #+#              #
#    Updated: 2026/11/07 00:00:00 by rperez-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# One function per file, grouped by theme under sources/; headers under include/.
SRC_DIR		= sources
INC_DIR		= include
HEADERS		= $(INC_DIR)/libft.h $(addprefix $(INC_DIR)/core/libft_,libs.h structs.h)

CHAR_SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				  ft_toupper.c ft_tolower.c
MEMORY_SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
				  ft_memcmp.c ft_calloc.c
STRING_SRCS	= ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
				  ft_strncmp.c ft_strnstr.c ft_strdup.c
CONVERT_SRCS	= ft_atoi.c ft_itoa.c
NEW_STRING_SRCS	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
				  ft_striteri.c
OUTPUT_SRCS	= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
LIST_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				  ft_lstmap.c

SRCS		= $(addprefix $(SRC_DIR)/char/,$(CHAR_SRCS)) \
			  $(addprefix $(SRC_DIR)/memory/,$(MEMORY_SRCS)) \
			  $(addprefix $(SRC_DIR)/string/,$(STRING_SRCS)) \
			  $(addprefix $(SRC_DIR)/convert/,$(CONVERT_SRCS)) \
			  $(addprefix $(SRC_DIR)/new_string/,$(NEW_STRING_SRCS)) \
			  $(addprefix $(SRC_DIR)/output/,$(OUTPUT_SRCS)) \
			  $(addprefix $(SRC_DIR)/list/,$(LIST_SRCS))
OBJS		= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
