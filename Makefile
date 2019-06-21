natural_selection: main.cpp entity.h population.h
	g++ -g -Wall -Werror -std=c++11 -o natural_selection main.cpp -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -f *.out *.o natural_selection
