#tool/makefile
all:libpublic.a \
	libpublic.so

libpublic.a:public.h public.cpp
	g++ -c -o libpublic.a public.cpp

libpublic.so:public.h public.cpp
	g++ -fPIC -shared -o libpublic.so public.cpp

clean:
	rm -f libpublic.a libpublic.so
