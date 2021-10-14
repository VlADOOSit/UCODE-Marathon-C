all: copy MINILIBMX clean

copy:
	mkdir obj
	cp inc/*.h obj
	cp src/*.c obj
MINILIBMX:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/*.c
	
	ar -src minilibmx.a *.o
	ranlib minilibmx.a
	cp *.o obj
	

uninstall:
	rm -rf obj
	rm minilibmx.a

clean:
	rm *.o
	
	rm obj/*.h
	rm obj/*.c

reinstall:
	make uninstall
	make
    