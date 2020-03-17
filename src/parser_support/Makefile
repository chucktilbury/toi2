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
			assignment_rules.o \
			globals.o

SRCS	=	$(OBJS:.o=.c)
HEADERS	=	$(OBJS:.o=.h)

TARGET	=	../../lib/libparser_support.a
DEPS	= 	$(TARGET).dep

CC		=	gcc # clang
CARGS	=	-Wall
DEBUG	=	-g -DTRACE
HSRC	= 	-I../include -I../parser

.PHONY: all pretty clean all_clean

all: $(TARGET)

.c.o:
	$(CC) $(HSRC) $(CARGS) $(DEBUG) -c $< -o $@

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

$(DEPS): $(SRCS)
	$(CC) -M $(HSRC) $(SRCS) > $(DEPS)

pretty:
	indent $(SRCS) $(HEADERS)
	-rm -f *~

clean:
	-rm -f $(TARGET) $(OBJS) *.bak *~ $(DEPS) .indent.pro

-include $(DEPS)
