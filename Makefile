CC=clang
CFLAGS=-Wall -g
.PHONY: default clean check all
BIN=./bin/
SRC=./src/

default: all
all: newcow wildcow reading_cow tamagochi

check: test
	./test
	-@ rm -f test

$(BIN):
	mkdir $(BIN)

test: $(BIN)test.o $(BIN)parser.o
	$(CC) -o $@ $^


newcow: $(BIN)newcow.o $(BIN)parser.o $(BIN)showcow.o
	$(CC) -o $@ $^

wildcow: $(BIN)wildcow.o $(BIN)parser.o $(BIN)showcow.o
	$(CC) -o $@ $^

reading_cow: $(BIN)reading_cow.o $(BIN)showcow.o $(BIN)parser.o
	$(CC) -o $@ $^

tamagochi: $(BIN)tamagochi.o $(BIN)interface.o $(BIN)showcow.o $(BIN)parser.o
	$(CC) -o $@ $^

$(BIN)%.o : $(SRC)%.c | $(BIN)
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	-@rm -f $(BIN)*
	-@rm -f newcow wildcow reading_cow tamagochi

