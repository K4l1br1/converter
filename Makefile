# Компилятор и флаги
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I./include

# Каталоги
SRC_DIR := src
OBJ_DIR := build
BIN := unit_converter

# Все .cpp файлы из src
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Объектные файлы в build, путь сохраняется
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Правило по умолчанию - сборка
all: $(BIN)

# Линковка
$(BIN): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Компиляция .cpp -> .o с созданием папок
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка артефактов сборки
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
