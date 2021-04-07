CFLAGS = -O
CC = g++
SRC = src/main.cpp src/impl/cli.cpp src/impl/run.cpp src/impl/lexer.cpp src/impl/parser.cpp src/impl/get_val_str.cpp  src/impl/gen_val.cpp src/impl/input.cpp src/impl/occur.cpp
OBJ = $(SRC:.cpp = .o) 

kel99: $(OBJ)
	$(CC) $(CFLAGS) -o kelc $(OBJ)

clean:
	rm -f kelc