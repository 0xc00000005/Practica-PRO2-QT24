# Nombre del ejecutable
TARGET = a.out

# Compilador y opciones de compilación
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Archivos fuente y objetos
SRCS = main.cc Tienda.cc Cliente.cc Cjt_clientes.cc Hora.cc Cjt_cajas.cc Caja.cc
OBJS = $(SRCS:.cc=.o)

# Archivos de encabezado
HDRS = BinTree.hh Caja.hh Cliente.hh Cjt_clientes.hh Hora.hh PRO2Excepcio.hh Sala.hh Tienda.hh Cjt_cajas.hh Caja.hh

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos objeto
%.o: %.cc $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f *.o *.gch

.PHONY: all clean cleanall