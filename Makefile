# Makefile para compilar header.h, funcoes.c e main.c

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Werror

# Nome do executável
TARGET = meu_programa

# Lista de fontes
SOURCES = main.c ArvoreBinaria.c

# Nome do arquivo de cabeçalho
HEADERS = ArvoreBinaria.h

# Comando padrão quando você apenas digita 'make'
all: $(TARGET) run

# Regra para o alvo final
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Regra para verificar dependências
$(SOURCES): $(HEADERS)

# Regra para executar o programa
run:
	./$(TARGET)

# Regra para limpar os arquivos gerados durante a compilação
clean:
	rm -f $(TARGET)

# Regra para reconstruir o projeto do zero
rebuild: clean all

# Indica quais regras não são arquivos
.PHONY: all clean rebuild
