# makefile The Boys
# Carlos Maziero - DINF/UFPR, 2024/2
# Adaptado para incluir ftheboys.o e theboys.h

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g -std=c99
LDLIBS  = -lm
MAIN    = theboys
ENTREGA = $(MAIN)

# lista de arquivos de cabeçalho
# Adicionado theboys.h
HDR = fila.h fprio.h conjunto.h theboys.h

# lista de arquivos-objeto auxiliares
# Adicionado ftheboys.o e removido theboys.o (ele é tratado separadamente como MAIN)
OBJ = fila.o fprio.o ftheboys.o

# construir o executável
$(MAIN): $(MAIN).o $(OBJ) conjunto.o
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN).o $(OBJ) conjunto.o $(LDLIBS)

# construir o objeto principal
$(MAIN).o: $(MAIN).c $(HDR)

# construir os objetos auxiliares
ftheboys.o: ftheboys.c theboys.h
fila.o: fila.c fila.h
fprio.o: fprio.c fprio.h

# executar
run: $(MAIN)
	./$(MAIN)

# testar no Valgrind
valgrind: $(MAIN)
	valgrind --leak-check=full --track-origins=yes ./$(MAIN)

# gerar arquivo TGZ para entregar
tgz: clean
	-mkdir -p /tmp/$(USER)/$(ENTREGA)
	chmod 0700 /tmp/$(USER)/$(ENTREGA)
	cp *.c *.h conjunto.o makefile /tmp/$(USER)/$(ENTREGA)
	tar czvf $(ENTREGA).tgz -C /tmp/$(USER) $(ENTREGA)
	rm -rf /tmp/$(USER)
	@echo "Arquivo $(ENTREGA).tgz criado para entrega"

# limpar arquivos temporários
# Nota: conjunto.o NÃO é removido
clean:
	rm -f *~ $(OBJ) $(MAIN).o $(MAIN) /tmp/$(USER)/$(ENTREGA) $(ENTREGA).tgz