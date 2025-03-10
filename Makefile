#OBJS specifies which files to compile as part of the project
OBJS = entry/game.cpp src/tictactoe.cpp includes/tictactoe.h

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w


#OBJ_NAME specifies the name of our exectuable
OBJ_DIR = bin
OBJ_NAME = game


#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_DIR)/$(OBJ_NAME)

clean : 
	rm $(OBJ_DIR)/$(OBJ_NAME)