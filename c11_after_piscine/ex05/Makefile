CC = cc
CFLAGS = -Wall -Werror -Wextra
EXECUTABLE = do-op

SOURCES = do-op.c utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJECTS)
fclean: clean
	@rm -f $(EXECUTABLE)
.PHONY: all clean fclean