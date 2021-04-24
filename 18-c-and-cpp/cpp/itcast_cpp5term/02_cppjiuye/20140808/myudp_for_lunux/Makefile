CC=g++

CFLAGS += -D MYLINUX

SRCS=main.cpp\
	udp.cpp
OBJS=$(SRCS:.cpp=.o)

EXEC=myudp_for_linux

start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

.cpp.o:
	$(CC) -o $@ -c $<

clean:
	 rm -rf $(OBJS)
