OBJ = main.o gamemap.o gametile.o random_number.o position_checker.o
GCC_ARGS = -ansi -Wall -pedantic-errors

mapgen: main.o gamemap.o gametile.o random_number.o position_checker.o
		g++ $(GCC_ARGS) $^ -o $@

main.o: main.cpp gamemap.h random_number.h
	g++ $(GCC_ARGS) -c $^

gamemap.o: gamemap.cpp gamemap.h gametile.h
	g++ $(GCC_ARGS) -c $^

gametile.o: gametile.cpp
	g++ $(GCC_ARGS) -c $^

random_number.o: random_number.cpp
	g++ $(GCC_ARGS) -c $^

position_checker.o: position_checker.cpp gametile.h gamemap.h
	g++ $(GCC_ARGS) -c $^

clean:
	rm *.o
