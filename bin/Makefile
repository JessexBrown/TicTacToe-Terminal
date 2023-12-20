EXENAME = game

CXX = clang++
CXXFLAGS = -std=c++20 -g -O0 -Wall -Wextra

all : $(EXENAME)

# $(EXENAME): main.cc Food.hpp Food.o q5.o q5.hpp
# 	$(CXX) $(CXXFLAGS) main.cc Food.o q5.o -o $(EXENAME)

$(EXENAME): 
	$(CXX) $(CXXFLAGS) ../entry/game.cpp ../src/tictactoe.cpp -o game

# Food.o: Food.hpp Food.cc
# 	$(CXX) $(CXXFLAGS) -c Food.cc

# q5.o: q5.hpp q5.cc
# 	$(CXX) $(CXXFLAGS) -c q5.cc

.PHONY: clean
clean:
	rm -f *.o $(EXENAME)
