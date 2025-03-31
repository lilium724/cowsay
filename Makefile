CC=clang
CFLAGS=-Wall -g
.PHONY: default clean
BIN=./bin/
SRC=./src/

default: newcow

newcow: $(BIN)newcow.o
	$(CC) -o $@ $^

$(BIN)%.o : $(SRC)%.c
	$(CC) $(CFLAGS) -c -o $@ $^ 

clean:
	-@rm -f $(BIN)*
	-@rm -f newcow

