CC=clang
CFLAGS=-Wall -g
.PHONY: default clean check
BIN=./bin/
SRC=./src/

default: newcow

check: test
	./test
	-@ rm -f test

$(BIN):
	mkdir $(BIN)

test: $(BIN)test.o $(BIN)parser.o
	$(CC) -o $@ $^


newcow: $(BIN)newcow.o $(BIN)parser.o
	$(CC) -o $@ $^

$(BIN)%.o : $(SRC)%.c $(BIN)
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	-@rm -f $(BIN)*
	-@rm -f newcow

