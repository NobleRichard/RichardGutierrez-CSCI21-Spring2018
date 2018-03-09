all: ProjectB

ProjectB: main.o Base.o Gold.o Platinum.o Corporate.o 
	g++ -std=c++11 -Wall -g -o ProjectB main.o Base.o Gold.o Platinum.o Corporate.o

Corporate: Corporate.cpp
	g++ -std=c++11 -Wall -g -c Corporate.cpp Corporate.h

Platinum: Platinum.cpp
	g++ -std=c++11 -Wall -g -c Platinum.cpp Platinum.h
	
Gold: Gold.cpp
	g++ -std=c++11 -Wall -g -c Gold.cpp Gold.h

Base: Base.cpp
	g++ -std=c++11 -Wall -g -c Base.cpp Base.h
	
Main: main.cpp
	g++ -std=c++11 -Wall -g -c main.cpp

clean: 
	$(RM) count *.o *~