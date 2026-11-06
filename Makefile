# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 14:34:39 by rperez-t          #+#    #+#              #
#    Updated: 2026/10/30 15:47:13 by rperez-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include mk/colors.mk
include mk/config.mk
include mk/sources.mk

all: $(NAME)

$(NAME): $(OBJS)
	@$(call run,$(AR) $(NAME) $(OBJS))

%.o: %.c libft.h
	@$(call run,$(CC) $(CFLAGS) -I. -c $< -o $@)

clean:
	@$(call remove,$(OBJS),Removing the objects of libft,objects of libft)

fclean: clean
	@$(call remove,$(NAME),Removing the library $(NAME))

re: fclean all

.PHONY: all clean fclean re
