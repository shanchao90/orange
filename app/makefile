INCLUDEDIR=-I/home/shanc/orange/tool -I/home/shanc/orange/api
LIBDIR=-L/home/shanc/orange/tool -L/home/shanc/orange/api

all:demo1 server

demo1:demo1.cpp
	g++ -o demo1 demo1.cpp $(LIBDIR) $(INCLUDEDIR) -lpublic -lmyapi

server:server.cpp
	g++ -o server server.cpp

clean:
	rm -f demo1
