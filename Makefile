mapgen: main.o gamemap.o gametile.o random_number.o
	g++ main.o gamemap.o gametile.o random_number.o -o mapgen

main.o: main.cpp gamemap.h
	g++ -c main.cpp gamemap.h

gamemap.o: gamemap.cpp gamemap.h gametile.h
	g++ -c gamemap.cpp gamemap.h gametile.h

gametile.o: gametile.cpp gametile.h
	g++ -c gametile.cpp gametile.h

random_number.o: random_number.cpp
	g++ -c random_number.cpp

clean:
	rm *.o mapgen
