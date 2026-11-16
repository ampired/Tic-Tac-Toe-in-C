# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -g

# Nombre del ejecutable final (usa tres_en_raya.exe si estás en Windows)
TARGET = tres_en_raya

# Archivos fuente y objetos
SRCS = main.c menu.c jugador.c maquina.c tablero.c
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(TARGET)

# Enlazado final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilación de cada .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependencias de cabeceras (recompila si modificas un .h)
main.o: main.c menu.h
menu.o: menu.c menu.h jugador.h maquina.h tablero.h
jugador.o: jugador.c jugador.h tablero.h menu.h
maquina.o: maquina.c maquina.h jugador.h menu.h tablero.h
tablero.o: tablero.c tablero.h jugador.h maquina.h menu.h

# Limpiar archivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean