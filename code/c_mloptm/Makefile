CC = gcc

NAME = mloptm.exe
RELEASE_NAME = mloptm_release.exe

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

CC_FLAGS = -g -Wall
CC_FLAGS_RELEASE  = -O3
CC_LINKS = -lm $(CC_IN) -I $(INC_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/$(NAME)
RELEASE_TARGET = $(BIN_DIR)/$(RELEASE_NAME)

all: $(TARGET)

release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(OBJS)
	$(CC) $(CC_FLAGS_RELEASE) $(OBJS) -o $@ $(CC_LINKS)

$(TARGET): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@ $(CC_LINKS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ -I $(CC_LINKS)

clean:
	rm -r $(BIN_DIR)/*
	rm -r $(OBJ_DIR)/*

