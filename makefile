OBJS = src/main.c src/common.c src/startPage.c src/utils/button.c src/utils/image.c src/utils/quit.c src/utils/style.c
CC = gcc
WARNING_FLAGS = -Wall -Werror -Wextra 
INCLUDE_PATHS = -ID:/SDL/include -I./include
LIBRARY_PATHS = -LD:/SDL/lib
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf #-mwindows
OBJ_NAME = ./bin/BounceFrog

all : $(OBJS)
	$(CC) $(OBJS) $(WARNING_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(OBJ_NAME)
