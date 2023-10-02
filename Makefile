# Variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++11 -ftest-coverage -fprofile-arcs
LDFLAGS = -ftest-coverage -fprofile-arcs
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = bin
TARGET = meu_programa

# Lista de arquivos-fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Lista de objetos
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Regra padrão para construir o programa
all: $(BUILD_DIR) $(TARGET)

# Diretório de construção
$(BUILD_DIR):
    mkdir -p $(BUILD_DIR)

# Alvo final (programa)
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$(TARGET) $(OBJS)

# Regra para compilar arquivos de origem em objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Limpar objetos e programa
clean:
    rm -rf $(BUILD_DIR)

# Executar o programa
run: $(TARGET)
    ./$(BUILD_DIR)/$(TARGET)

.PHONY: all clean run