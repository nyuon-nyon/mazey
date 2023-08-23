CC = gcc
CFLAGS = -Wall -Wextra -g

SRC_FILES = main.c NM_algos.c NM_graph.c
OBJ_FILES = $(SRC_FILES:.c=.o)

show: $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) show
