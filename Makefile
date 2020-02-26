################################################################################
#
#	Make file for simple objects
#
################################################################################
PLATNAME := $(shell uname)

OBJS	=	errors.o \
			linked_lists.o \
			hash_table.o \
			xxhash.o \
			ast_tree.o \
			ast_attributes.o \
			parser_support.o \
			parser_states.o

OBJS1	=	main.o \
			scanner.o \
			parser.o

SRCS	=	$(OBJS:.o=.c)
SRCS1	=	$(OBJS1:.o=.c)
HEADERS	=	$(OBJS:.o=.h)

TARGET	=	toi
DEPS	= 	$(TARGET).dep

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

-include $(DEPS)

$(DEPS): $(SRCS) $(SRCS1)
	$(CC) -M $(SRCS) $(SRCS1) > $(DEPS)

$(TARGET): $(OBJS) $(OBJS1) $(DEPS)
	$(CC) $(CARGS) $(DEBUG) $(OBJS1) $(OBJS) -o $(TARGET) $(LIBS)

parser.c parser.h: parser.y scanner.h
	bison --report=lookahead -tvdo parser.c parser.y

scanner.c: scanner.l parser.h scanner.h
	flex -o scanner.c scanner.l

pretty: clean
	indent $(SRCS) $(HEADERS)
	-rm -f *~

clean:
	-rm -f scanner.c parser.c parser.h parser.output $(OBJS) $(OBJS1) $(TARGET) $(DEPS) *.bak *~

