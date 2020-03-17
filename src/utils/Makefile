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
			lifo.o \
			fifo.o

SRCS	=	$(OBJS:.o=.c)
HEADERS	=	$(OBJS:.o=.h)

TARGET	=	../../lib/libutils.a
DEPS	= 	$(TARGET).dep

CC		=	gcc #clang
CARGS	=	-Wall
HSEARCH	=	-I../parser -I../include
DEBUG	=	-g -DTRACE

.PHONY: all pretty clean all_clean

all: $(TARGET)

.c.o:
	$(CC) $(HSEARCH) $(CARGS) $(DEBUG) -c $< -o $@

$(TARGET): $(OBJS) $(DEPS)
	ar rcs $(TARGET) $(OBJS) $(OBJS1)

$(DEPS): $(SRCS)
	$(CC) -M $(HSEARCH) $(SRCS) > $(DEPS)

pretty:
	indent $(SRCS) $(HEADERS)
	-rm -f *~

clean:
	-rm -f $(OBJS) $(TARGET) *.bak *~ $(TARGET) $(DEPS) .indent.pro

-include $(DEPS)
