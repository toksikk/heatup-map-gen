mapgen: main.o gamemap.o gametile.o random_number.o position_checker.o
	g++ main.o gamemap.o gametile.o random_number.o position_checker.o -o mapgen

main.o: main.cpp gamemap.h random_number.h
	g++ -c main.cpp gamemap.h random_number.h

gamemap.o: gamemap.cpp gamemap.h gametile.h
	g++ -c gamemap.cpp gamemap.h gametile.h

gametile.o: gametile.cpp gametile.h
	g++ -c gametile.cpp gametile.h

random_number.o: random_number.cpp
	g++ -c random_number.cpp

position_checker.o: position_checker.cpp gametile.h gamemap.h
	g++ -c position_checker.cpp gametile.h gamemap.h

clean:
	rm *.o
