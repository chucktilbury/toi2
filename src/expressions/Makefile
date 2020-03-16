PLATNAME := $(shell uname)

TARG_DIR	= ../../lib/
SRCS	=	arith.c \
			bitwise.c \
			boolean.c \
			evaluate.c \
			expressions.c \
			unary.c

OBJS	=	$(SRCS:.c=.o)
#OBJS	=	$(foreach var, $(TOBJ), $(TARG_DIR)$(var))
#HEADERS	=	$(OBJS:.o=.h)

TARGET	=	$(TARG_DIR)libexpressions.a
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
	-rm -f $(TARGET) $(OBJS) *.bak *~

all_clean: clean
	-rm -f  $(DEPS) .indent.pro

-include $(DEPS)
