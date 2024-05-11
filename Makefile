CC = g++
CFLAGS = -Wall -std=c++11 `wx-config --cxxflags`
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/compiled
OUTPUT_DIR = $(BUILD_DIR)/output
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
TARGET = $(OUTPUT_DIR)/OpenMedia

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) `wx-config --libs`

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)

run:
	./$(TARGET)

.PHONY: run
