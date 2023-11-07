CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = srcs
INC_DIR = includes

SOURCES := $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(SRC_DIR)/%.o,$(SOURCES))

LIB_NAME = libft.a

all:$(LIB_NAME)

$(LIB_NAME): $(OBJECTS)
	ar rcs $(LIB_NAME) $^
	ranlib $(LIB_NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -I$(INC_DIR) -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
