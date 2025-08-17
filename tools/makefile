all:liblog.a liblog.so

liblog.a:log.h log.c
	gcc -c -o liblog.a log.c
liblog.so:log.h log.c
	gcc -fPIC -shared -o liblog.so log.c

clean:
	rm -f liblog.a liblog.so
