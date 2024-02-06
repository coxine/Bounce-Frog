OBJS = src/main.c src/utils/quit.c src/utils/styleOp.c src/config/elementStyle.c
CC = gcc
WARNING_FLAGS = -Wall -Werror -Wextra 
INCLUDE_PATHS = -ID:/SDL/include -I./include
LIBRARY_PATHS = -LD:/SDL/lib
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2
OBJ_NAME = ./bin/main

all : $(OBJS)
	$(CC) $(OBJS) $(WARNING_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(OBJ_NAME)