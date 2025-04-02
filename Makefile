CC=clang
CFLAGS=-Wall -g
.PHONY: default clean
BIN=./bin/
SRC=./src/

default: $(BIN) newcow

$(BIN):
	mkdir $(BIN)

newcow: $(BIN)newcow.o $(BIN)parser.o
	$(CC) -o $@ $^

$(BIN)%.o : $(SRC)%.c
	$(CC) $(CFLAGS) -c -o $@ $^ 

clean:
	-@rm -f $(BIN)*
	-@rm -f newcow

