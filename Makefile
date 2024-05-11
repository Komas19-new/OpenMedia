CC = g++
CFLAGS = -Wall -std=c++11
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/compiled
OUTPUT_DIR = $(BUILD_DIR)/output
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
TARGET = $(OUTPUT_DIR)/OpenMedia
CSS = $(wildcard $(SRC_DIR)/css/fontawesome*.css)
GIT_STATUS = $(shell git status --porcelain)
VERSION = $(if $(strip $(GIT_STATUS)),Unknown,$(shell git rev-parse --short HEAD))

$(TARGET): $(OBJ) $(CSS)
	mkdir -p $(OUTPUT_DIR)/css
	$(CC) -o $@ $(OBJ) $(CFLAGS)
	cp $(CSS) $(OUTPUT_DIR)/css/
	echo "$(VERSION)" > $(OUTPUT_DIR)/VERSION

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)

run:
	./$(TARGET)

.PHONY: run
