# Patrick Ging Makefile

main:
	g++ -std=c++11 *.cpp

debug:
	g++ -std=c++11 -O0 -g *.cpp 

clean:
	rm -rf *.out *.o ./main