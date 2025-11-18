# Компилятор и флаги
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I./include

# Каталоги
SRC_DIR := src
OBJ_DIR := build
BIN := unit_converter

# Файлы из поддиректории src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Объектные файлы в build
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Правило по умолчанию
all: $(BIN)

# Test target
TEST_BIN := test_runner

test: CXXFLAGS += -I./tests
test: $(TEST_BIN)

$(TEST_BIN): $(SRC_DIR)/converter.cpp $(SRC_DIR)/distance.cpp $(SRC_DIR)/temperature.cpp $(SRC_DIR)/weight.cpp tests/test_runner.cpp
	$(CXX) $(CXXFLAGS) $^ -o $(TEST_BIN)

# Линковка
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Создание директории для объектных файлов
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Компиляция объектов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка артефактов
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(BIN)
	rm -f $(TEST_BIN)

# Установка (для deb пакета)
DESTDIR ?= /
PREFIX ?= /usr
install: $(BIN)
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 $(BIN) $(DESTDIR)$(PREFIX)/bin/

.PHONY: all clean install
