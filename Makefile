# Configuration

CC		= gcc
LD		= gcc
AR		= ar
CFLAGS		= -g -std=gnu99 -Wall -Iinclude -fPIC
LDFLAGS		= -Llib
ARFLAGS		= rcs

# Variables

LIBRARY_HEADERS = include/lsort.h
LIBRARY_SOURCES = src/node.c src/list.c
LIBRARY_OBJECTS	= $(LIBRARY_SOURCES:.c=.o)
STATIC_LIBRARY  = lib/liblsort.a
LSORT_PROGRAM	= bin/lsort

TEST_SOURCES    = $(wildcard tests/unit_*.c)
TEST_OBJECTS	= $(TEST_SOURCES:.c=.o)
TEST_PROGRAMS   = $(subst tests,bin,$(basename $(TEST_OBJECTS)))

# Rules

all:	$(LSORT_PROGRAM)

%.o:	%.c $(LIBRARY_HEADERS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -c -o $@ $<

bin/%:	tests/%.o $(STATIC_LIBRARY)
	@echo "Linking $@"
	@$(LD) $(LDFLAGS) -o $@ $^

$(LSORT_PROGRAM):	src/lsort.o $(STATIC_LIBRARY)
	@echo "Linking $@"
	@$(LD) $(LDFLAGS) -o $@ $^

$(STATIC_LIBRARY):	$(LIBRARY_OBJECTS)
	@echo "Linking $@"
	@$(AR) $(ARFLAGS) $@ $^

test:		
	@$(MAKE) -sk test-all

test-all:	test-node test-list test-lsort

test-node:	bin/unit_node
	@./bin/test_node.sh

test-list:	bin/unit_list
	@./bin/test_list.sh

test-lsort:	$(LSORT_PROGRAM)
	@./bin/test_lsort.sh

clean:
	@echo "Removing objects"
	@rm -f $(LIBRARY_OBJECTS) $(TEST_OBJECTS) src/*.o

	@echo "Removing static library"
	@rm -f $(STATIC_LIBRARY)

	@echo "Removing tests"
	@rm -f $(TEST_PROGRAMS)

	@echo "Removing lsort"
	@rm -f $(LSORT_PROGRAM)

.PRECIOUS: %.o
