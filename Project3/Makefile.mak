CC = g++
CFLAGS = -Wall -Werror -std=c++17

all: main

main: main.o LoadBalancer.o WebServer.o
    $(CC) $(CFLAGS) -o main main.o LoadBalancer.o WebServer.o

main.o: main.cpp LoadBalancer.h WebServer.h Request.h
    $(CC) $(CFLAGS) -c main.cpp

LoadBalancer.o: LoadBalancer.cpp LoadBalancer.h WebServer.h Request.h
    $(CC) $(CFLAGS) -c LoadBalancer.cpp

WebServer.o: WebServer.cpp WebServer.h Request.h
    $(CC) $(CFLAGS) -c WebServer.cpp

clean:
    rm -f *.o main
