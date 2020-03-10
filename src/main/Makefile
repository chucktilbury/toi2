
PLATNAME := $(shell uname)

OBJS	=	main.o
SRCS	=	$(OBJS:.o=.c)
#HEADERS	=	$(OBJS:.o=.h)

TARGET	=	../../bin/toi
DEPS	= 	$(TARGET).dep

CC		=	gcc # clang
CARGS	=	-Wall
HSRC	=	-I../parser -I../utils -I../abstract_tree
DEBUG	=	-g -DTRACE

LIBDIRS	=	-L../../lib
ifeq ($(PLATNAME), Linux)
	LIBS	=	$(LIBDIRS) -lparser -labstree -lutils -lexpressions -ll -ly
else ifeq ($(PLATNAME), MSYS_NT-6.1)
	LIBS	=	$(LIBDIRS) -L/c/MinGW/msys/1.0/lib -lparser -lutils -lfl -ly
endif

.PHONY: all pretty clean all_clean
all: $(TARGET)

.c.o:
	$(CC) $(HSRC) $(CARGS) $(DEBUG) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(HSRC) $(CARGS) $(DEBUG) $(OBJS) -o $(TARGET) $(LIBS)

$(DEPS): $(SRCS)
	$(CC) $(HSRC) -MM $(SRCS) > $(DEPS)

pretty:
	indent $(SRCS) $(HEADERS)
	-rm -f *~

clean:
	-rm -f $(OBJS) *.bak *~

all_clean: clean
	-rm -f $(TARGET) $(DEPS) .indent.pro

-include $(DEPS)
