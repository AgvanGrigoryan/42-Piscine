CC = cc
CFLAGS = -Wall -Werror -Wextra

EXECUTABLE = ft_display_file

SOURCE = ft_display_file.c 
OBJECTS = $(SOURCE:.c=.o)

all:$(EXECUTABLE)
	
$(EXECUTABLE):$(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(EXECUTABLE)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(EXECUTABLE)

.PHONY: all clean fclean
