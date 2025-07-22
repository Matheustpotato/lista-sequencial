# Nome do compilador
CXX       = g++

# Flags de compilação
CXXFLAGS  = -Wall -Wextra -std=c++11

# Nome do executável
TARGET    = sequencial

# Arquivo fonte
SRC       = sequencial.cpp

# Arquivo objeto
OBJ       = $(SRC:.cpp=.o)

# Regra padrão: compila tudo
all: $(TARGET)

# Linka o executável a partir dos objetos
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regra genérica para compilar .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
	@rm -f $(OBJ) $(TARGET)
	@echo "Limpo: $(OBJ) e $(TARGET) removidos."
