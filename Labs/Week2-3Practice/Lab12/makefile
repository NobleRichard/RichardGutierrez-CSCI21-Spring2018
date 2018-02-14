all: item

item: food_item.o item.o Lab_12_unit_test.o
	g++ -Wall -g -o item food_item.o item.o Lab_12_unit_test.o

lab12test: food.cpp
	g++ -Wall -g -c food_item.cpp food_item.h

lab12: item.cpp
	g++ -Wall -g -c item.cpp item.h
	
unittest: Lab_12_unit_test.cpp
	g++ -Wall -g -c Lab_12_unit_test.cpp