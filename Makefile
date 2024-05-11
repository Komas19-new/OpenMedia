CC = g++
CFLAGS = -Wall -std=c++11
SRC_DIR = src
BUILD_DIR = build/compiled
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
TARGET = $(BUILD_DIR)/OpenMedia
CSS = $(SRC_DIR)/css/fontawesome-6.5.2.css
GIT_STATUS = $(shell git status --porcelain)
VERSION = $(if $(strip $(GIT_STATUS)),Unknown,$(shell git rev-parse --short HEAD))

$(TARGET): $(OBJ) $(CSS)
	$(CC) -o $@ $(OBJ) $(CFLAGS)
	cp $(CSS) $(BUILD_DIR)/css/fontawesome-6.5.2.css
	echo "$(VERSION)" > $(BUILD_DIR)/VERSION

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)/css
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

run:
	./$(TARGET)

.PHONY: run
