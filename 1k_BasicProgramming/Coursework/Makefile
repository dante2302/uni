# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Directories
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = .

# Source files and output binary
SRCS = main.cpp menu.cpp utils.cpp participants.cpp validation.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
TARGET = $(BIN_DIR)/program

# Default rule
all: $(TARGET)

# Create the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the obj directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean rule to remove compiled files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets to prevent conflicts with file names
.PHONY: all clean