CC = gcc
CFLAGS = -Iinclude -Wall
FORMATTER ?= $(shell command -v clang-format || command -v clang-format-18 || command -v clang-format-17 || command -v clang-format-16)
SRC = src/main.c src/createfile.c src/writefile.c src/appendfile.c src/copyfile.c src/readfile.c \
      src/deletefile.c src/renamefile.c src/movefile.c src/createdir.c src/deletedir.c src/listdir.c
HDR = include/appendfile.h include/copyfile.h include/createdir.h include/createfile.h include/deletedir.h \
	include/deletefile.h include/listdir.h include/movefile.h include/readfile.h include/renamefile.h include/writefile.h
OBJ_DIR = build
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
TARGET = bin/filemanager

.PHONY: all clean format

all: $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bin:
	mkdir -p bin

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ) | bin
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

format:
	@test -n "$(FORMATTER)" || { echo "Error: clang-format not found (tried clang-format, clang-format-18, clang-format-17, clang-format-16)"; exit 1; }
	$(FORMATTER) -i $(SRC) $(HDR)