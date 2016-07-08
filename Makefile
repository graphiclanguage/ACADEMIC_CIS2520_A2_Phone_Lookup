IDIR=include
CC=gcc
CFLAGS=-Wall -std=c99 -I$(IDIR) -g
vpath %.c ./src

SOURCES=$(filter-out $(wildcard src/*Test.c), $(wildcard src/*.c))
OBJECTS=$(patsubst src/%.c,obj/%.o,$(SOURCES))
EXECUTABLE=bin/phoneLookup

HASH_SRC=src/hashTable.c src/hashTest.c src/linkedList.c
HASH_OBJ=$(patsubst src/%.c,obj/%.o,$(HASH_SRC))

LIST_SRC=src/listTest.c src/linkedList.c
LIST_OBJ=$(patsubst src/%.c,obj/%.o,$(LIST_SRC))

all: test program

test: hashTest listTest

hashTest: $(HASH_OBJ)
	$(CC) $(CFLAGS) -o bin/hashTest $(HASH_OBJ)

listTest: $(LIST_OBJ)
	$(CC) $(CFLAGS) -o bin/listTest $(LIST_OBJ)
	
program: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)
	
obj/%.o: %.c
	@echo $<
	@$ $(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o bin/*