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

SRCS	=	$(OBJS:.o=.c)
HEADERS	=	$(OBJS:.o=.h)

TARGET	=	../../lib/libutils.a
DEPS	= 	$(TARGET).dep

CC		=	clang
CARGS	=	-Wall
HSEARCH	=	-I../parser
DEBUG	=	-g -DTRACE

.c.o:
	$(CC) $(HSEARCH) $(CARGS) $(DEBUG) -c $< -o $@

all: $(TARGET)

-include $(DEPS)

$(DEPS): $(SRCS) $(SRCS1)
	$(CC) -M $(HSEARCH) $(SRCS) $(SRCS1) > $(DEPS)

$(TARGET): $(OBJS) $(OBJS1) $(DEPS)
	ar rcs $(TARGET) $(OBJS) $(OBJS1)

pretty: clean
	indent $(SRCS) $(HEADERS)
	-rm -f *~

clean:
	-rm -f $(OBJS) $(TARGET) $(DEPS) *.bak *~

