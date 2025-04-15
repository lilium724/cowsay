CC=clang
CFLAGS=-Wall -g
.PHONY: default clean check
BIN=./bin/
SRC=./src/

all: newcow wildcow reading_cow

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

reading_cow: $(BIN)reading_cow.o $(BIN)showcow.o
	$(CC) -o $@ $^

$(BIN)%.o : $(SRC)%.c $(BIN)
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	-@rm -f $(BIN)*
	-@rm -f newcow

