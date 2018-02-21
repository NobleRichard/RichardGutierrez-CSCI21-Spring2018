all: ProjectB

ProjectB: main.o Base.o Gold.o Platinum.o Corporate.o 
	g++ -Wall -std=c++11 -o ProjectB main.o Base.o Gold.o Platinum.o Corporate.o

Corporate: Corporate.cpp
	g++ -Wall -std=c++11 -c Corporate.cpp Corporate.h

Platinum: Platinum.cpp
	g++ -Wall -std=c++11 -c Platinum.cpp Platinum.h
	
Gold: Gold.cpp
	g++ -Wall -std=c++11 -c Gold.cpp Gold.h

Base: Base.cpp
	g++ -Wall -std=c++11 -c Base.cpp Base.h
	
Main: main.cpp
	g++ -Wall -std=c++11 main.cpp

clean: 
	$(RM) count *.o *~
	