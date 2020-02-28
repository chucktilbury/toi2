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

CC		=	clang
CARGS	=	-Wall
DEBUG	=	-g -DTRACE
HSRC	= 	-I../utils -I../parser

.c.o:
	$(CC) $(HSRC) $(CARGS) $(DEBUG) -c $< -o $@

all: $(TARGET)

-include $(DEPS)

$(DEPS): $(SRCS) $(SRCS1)
	$(CC) -M $(HSRC) $(SRCS) > $(DEPS)

$(TARGET): $(OBJS) $(DEPS)
	ar rcs $(TARGET) $(OBJS)

pretty: clean
	indent $(SRCS) $(HEADERS)
	-rm -f *~

clean:
	-rm -f $(OBJS) $(TARGET) $(DEPS) *.bak *~

