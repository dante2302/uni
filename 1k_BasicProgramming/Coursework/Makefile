# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17
LIBS = -lpthread -lgtest

# Directories
SRC_DIR = src
OBJ_DIR = obj
OUT_DIR = .

# List of source files
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/menu/menu.cpp \
       $(SRC_DIR)/utils/utils.cpp \
       $(SRC_DIR)/participants/participants.cpp \
       $(SRC_DIR)/validation/validation.cpp \

# List of object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Name of the output executable
OUT = $(OUT_DIR)/program.out

# Default target
all: $(OUT)

# Rule to link object files to create the executable
$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile .cpp files to .o object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/$(dir $*) # Ensure subdirectories for object files are created
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LIBS)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR)

# Rebuild everything
rebuild: clean all

.PHONY: all clean rebuild