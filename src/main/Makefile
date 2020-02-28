
PLATNAME := $(shell uname)

OBJS	=	main.o
SRCS	=	$(OBJS:.o=.c)
#HEADERS	=	$(OBJS:.o=.h)

TARGET	=	../../bin/toi
DEPS	= 	$(TARGET).dep

CC		=	clang
CARGS	=	-Wall
HSRC	=	-I../parser -I../utils -I../abstract_tree
DEBUG	=	-g -DTRACE

LIBDIRS	=	-L../../lib
ifeq ($(PLATNAME), Linux)
	LIBS	=	$(LIBDIRS) -lparser -labstree -lutils -ll -ly
else ifeq ($(PLATNAME), MSYS_NT-6.1)
	LIBS	=	$(LIBDIRS) -L/c/MinGW/msys/1.0/lib -lparser -lutils -lfl -ly
endif

.c.o:
	$(CC) $(HSRC) $(CARGS) $(DEBUG) -c $< -o $@

all: $(TARGET)

-include $(DEPS)

$(DEPS): $(SRCS) $(SRCS1)
	$(CC) $(HSRC) -M $(SRCS) $(SRCS1) > $(DEPS)

$(TARGET): $(OBJS) $(OBJS1) $(DEPS)
	$(CC) $(HSRC) $(CARGS) $(DEBUG) $(OBJS) -o $(TARGET) $(LIBS)

pretty: clean
	indent $(SRCS) $(HEADERS)
	-rm -f *~

clean:
	-rm -f $(OBJS) $(TARGET) $(DEPS) *.bak *~

