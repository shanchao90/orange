INCLUDEDIR=-I/home/shanc/orange/tool -I/home/shanc/orange/api
LIBDIR=-L/home/shanc/orange/tool -L/home/shanc/orange/api

all:demo1 server demo_server demo_client main

demo1:demo1.cpp
	g++ -o demo1 demo1.cpp $(LIBDIR) $(INCLUDEDIR) -lpublic -lmyapi

server:server.cpp
	g++ -o server server.cpp

demo_server:demo_server.cpp
	g++ -o demo_server demo_server.cpp

demo_client:demo_client.cpp
	g++ -o demo_client demo_client.cpp

main:main.c
	gcc -o main main.c

clean:
	rm -f demo1
