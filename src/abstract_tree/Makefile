################################################################################
#
#	Make file for simple objects
#
################################################################################
PLATNAME := $(shell uname)

OBJS	=	ast_tree.o \
			ast_attributes.o

SRCS	=	$(OBJS:.o=.c)
HEADERS	=	$(OBJS:.o=.h)

TARGET	=	../../lib/libabstree.a
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
	-rm -f $(OBJS) *.bak *~

all_clean: clean
	-rm -f $(TARGET) $(DEPS) .indent.pro

-include $(DEPS)
