CC=clang
CFLAGS=-Wall -g
.PHONY: default clean check
BIN=./bin/
SRC=./src/

default: $(BIN) newcow

check: test
	./test
	-@ rm -f test

$(BIN):
	mkdir $(BIN)

test: $(BIN)test.o $(BIN)parser.o
	$(CC) -o $@ $^

$(BIN)test.o : $(SRC)test.c
	$(CC) $(CFLAGS) -Wno-incompatible-pointer-types-discards-qualifiers -c -o $@ $^

newcow: $(BIN)newcow.o $(BIN)parser.o
	$(CC) -o $@ $^

$(BIN)%.o : $(SRC)%.c
	$(CC) $(CFLAGS) -c -o $@ $^ 

clean:
	-@rm -f $(BIN)*
	-@rm -f newcow

