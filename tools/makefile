all:libmylk.a libmylk.so

#liblog.a:log.h log.c
#	gcc -c -o liblog.a log.c
#liblog.so:log.h log.c
#	gcc -fPIC -shared -o liblog.so log.c
libmylk.a:mylk.h mylk.c
	gcc -c -o libmylk.a mylk.c
libmylk.so:mylk.h mylk.c
	gcc -fPIC -shared -o libmylk.so mylk.c


clean:
	rm -f liblog.a liblog.so libmylk.a libmylk.so
