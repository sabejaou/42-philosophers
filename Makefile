# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 10:00:00 by sabejaou          #+#    #+#              #
#    Updated: 2024/05/30 10:00:00 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS = $(wildcard $(SRC_DIR)/core/*.c) \
	   $(wildcard $(SRC_DIR)/philosopher/*.c) \
	   $(wildcard $(SRC_DIR)/utils/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread
INCLUDES = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Edition des liens..."
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)
	@echo "Binaire $(NAME) créé avec succès !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage terminé !"

fclean: clean
	@echo "Nettoyage complet..."
	@rm -f $(NAME)
	@echo "Nettoyage complet terminé !"

re: fclean all

run: all
	./$(NAME) 5 800 200 200

.PHONY: all clean fclean re run 