################################################################################
#
#	Make file for simple objects
#
################################################################################
PLATNAME := $(shell uname)

OBJS	=	module_rules.o \
			import_rules.o \
			class_def_rules.o \
			data_def_rules.o \
			function_def_rules.o \
			expression_def_rules.o \
			function_call_rules.o \
			common_branch_rules.o \
			literal_value_rules.o \
			for_loop_rules.o \
			if_else_rules.o \
			while_rules.o \
			except_rules.o \
			switch_case_rules.o \
			assignment_rules.o

OBJS1	=	scanner.o \
			parser.o

SRCS	=	$(OBJS:.o=.c)
SRCS1	=	$(OBJS1:.o=.c)
HEADERS	=	$(OBJS:.o=.h)

TARGET	=	../../lib/libparser.a
DEPS	= 	$(TARGET).dep

CC		=	gcc # clang
CARGS	=	-Wall
DEBUG	=	-g -DTRACE
HSRC	= 	-I../utils -I../abstract_tree -I../expressions

.PHONY: all pretty clean all_clean

all: $(TARGET)

.c.o:
	$(CC) $(HSRC) $(CARGS) $(DEBUG) -c $< -o $@

$(TARGET): $(OBJS) $(OBJS1)
	ar rcs $(TARGET) $(OBJS) $(OBJS1)

$(DEPS): $(SRCS) $(SRCS1)
	$(CC) -M $(HSRC) $(SRCS) $(SRCS1) > $(DEPS)

parser.c parser.h: parser.y scanner.h
	bison --report=lookahead -tvdo parser.c parser.y

scanner.c: scanner.l parser.h scanner.h
	flex -o scanner.c scanner.l

pretty:
	indent $(SRCS) $(HEADERS)
	-rm -f *~

clean:
	-rm -f parser.output $(OBJS) $(OBJS1) *.bak *~

all_clean: clean
	-rm -f scanner.c parser.c parser.h $(TARGET) $(DEPS) .indent.pro

-include $(DEPS)

