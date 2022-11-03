CXXFLAGS=--coverage -g -O0

main: main.o funcs.o
	g++ -o main --coverage -g -O0 main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests --coverage -g -O0 tests.o funcs.o
	./tests
	gcovr 2> /dev/null > /dev/null
	gcovr --html-details coverage.html

tests.o: tests.cpp funcs.h

main.o: main.cpp funcs.h

funcs.o: funcs.cpp funcs.h

clean:
	rm -f main.o fact.o tests.o *gcda *html *gcno
