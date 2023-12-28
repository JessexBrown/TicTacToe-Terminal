EXENAME = game

CXX = clang++
CXXFLAGS = -std=c++20 -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): 
	$(CXX) $(CXXFLAGS) ../entry/game.cpp ../src/tictactoe.cpp -o game

.PHONY: clean
clean:
	rm -f *.o $(EXENAME)
