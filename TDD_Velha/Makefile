all: testa_velha
	./testa_velha

compile: testa_velha.cpp velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage testa_velha.cpp velha.o -o testa_velha

velha.o: velha.cpp velha.hpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp -o velha.o
	
testa_velha: testa_velha.cpp velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage testa_velha.cpp velha.o -o testa_velha
	
test: testa_velha
	./testa_velha

gcov: testa_velha
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage testa_velha.cpp velha.o -o testa_velha
	./testa_velha
	gcov *.cpp

cpplint: testa_velha.cpp velha.cpp velha.hpp
	cpplint --exclude=catch.hpp *.*
	 
debug: testa_velha.cpp velha.cpp velha.hpp
	g++ -std=c++11 -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall -g velha.o testa_velha.cpp -o testa_velha
	gdb ./testa_velha
	
	
cppcheck: testa_velha.cpp   velha.cpp velha.hpp
	cppcheck  --enable=warning .

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_velha

clean:
	rm -rf *.o *.exe *.gc* testa_velha 
