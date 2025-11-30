# Nome do compilador
CXX = g++

# Flags de compilação:
# -Wall: Mostra todos os avisos (warnings)
# -g: Adiciona informações de debug
# -std=c++17: Usa o padrão C++17 (pode mudar para c++11 ou c++20 se preferir)
# -I Headers: Diz ao compilador para procurar os .h dentro da pasta Headers
CXXFLAGS = -Wall -g -std=c++17 -I Headers

# Nome do executável final
TARGET = clinica

# Diretórios
SRC_DIR = Implementations
OBJ_DIR = obj

# Encontra todos os arquivos .cpp dentro da pasta Implementations
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Cria a lista de arquivos objeto (.o) baseada nos arquivos .cpp
# Exemplo: Implementations/Medico.cpp vira obj/Medico.o
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Regra principal (o que é executado ao digitar apenas 'make')
all: $(TARGET)

# Linkagem: junta todos os objetos para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Compilação concluída com sucesso! Executável: ./$(TARGET)"

# Compilação: transforma cada .cpp em .o
# A flag -c indica que é apenas compilação, não linkagem
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar arquivos temporários e o executável
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Regra para rodar o programa
run: all
	./$(TARGET)

.PHONY: all clean run