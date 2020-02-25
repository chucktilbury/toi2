################################################################################
#
#	Make file for simple objects
#
################################################################################
PLATNAME := $(shell uname)

OBJS	=	errors.o \
			main.o \
			linked_lists.o \
			hash_table.o \
			xxhash.o \
			abstract_tree.o

OBJS1	=	scanner.o \
			parser.o

HEADERS	=	errors.h \
			scanner.h \
			hash_table.h \
			linked_lists.h \
			xxhash.h \
			abstract_tree.h

SRCS	=	$(OBJS:.o=.c)

TARGET	=	toi

CC		=	clang
CARGS	=	-Wall
DEBUG	=	-g -DTRACE

ifeq ($(PLATNAME), Linux)
	LIBS	=	-ll -ly
else ifeq ($(PLATNAME), MSYS_NT-6.1)
	LIBS	=	-L/c/MinGW/msys/1.0/lib -lfl -ly
endif

.c.o:
	$(CC) $(CARGS) $(DEBUG) -c $< -o $@

all: $(TARGET)

big: pretty $(TARGET)

$(TARGET): $(OBJS1) $(OBJS)
	$(CC) $(CARGS) $(DEBUG) $(OBJS1) $(OBJS) -o $(TARGET) $(LIBS)

parser.c parser.h: parser.y scanner.h
	bison --report=lookahead -tvdo parser.c parser.y

scanner.c: scanner.l parser.h scanner.h
	flex -o scanner.c scanner.l

main.o: main.c $(HEADERS)
scanner.o: scanner.c scanner.h parser.h
errors.o: errors.c errors.h
parser.o: parser.c errors.h
linked_lists.o: linked_lists.c linked_lists.h
hash_table.o: hash_table.c hash_table.h
xxhash.o: xxhash.c xxhash.h
abstract_tree.o: abstract_tree.c abstract_tree.h

pretty: clean
	indent $(SRCS) $(HEADERS)

clean:
	-rm -f scanner.c parser.c parser.h parser.output $(OBJS) $(OBJS1) $(TARGET)

list_test: scanner.o errors.o parser.o logging.o utils.c
	$(CC) -DTESTING_LIST -o list_test $?
