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
			abstract_tree.o \
			ast_attributes.o

OBJS1	=	scanner.o \
			parser.o

HEADERS	=	errors.h \
			scanner.h \
			hash_table.h \
			linked_lists.h \
			xxhash.h \
			abstract_tree.h \
			ast_attributes.h

SRCS	=	$(OBJS:.o=.c)
SRCS1	=	$(OBJS1:.o=.c)

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

$(DEPS): $(SRCS) $(SRCS1)
	$(CC) -M $(SRCS) $(SRCS1) > $(DEPS)

$(TARGET): $(OBJS1) $(OBJS) $(DEPS)
	$(CC) $(CARGS) $(DEBUG) $(OBJS1) $(OBJS) -o $(TARGET) $(LIBS)

parser.c parser.h: parser.y scanner.h
	bison --report=lookahead -tvdo parser.c parser.y

scanner.c: scanner.l parser.h scanner.h
	flex -o scanner.c scanner.l

-include $(DEPS)

pretty: clean
	indent $(SRCS) $(HEADERS)

clean:
	-rm -f scanner.c parser.c parser.h parser.output $(OBJS) $(OBJS1) $(TARGET) $(DEPS) *.bak *~

