# Nombre del ejecutable
TARGET = program.exe

# Compilador y opciones de compilación
CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

# Archivos fuente y objetos
SRCS = program.cc Tienda.cc Cliente.cc Cjt_clientes.cc Hora.cc Cjt_cajas.cc Caja.cc
OBJS = $(SRCS:.cc=.o)

# Archivos de encabezado
HDRS = BinTree.hh Caja.hh Cliente.hh Cjt_clientes.hh Hora.hh PRO2Excepcio.hh Tienda.hh Cjt_cajas.hh Caja.hh

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

# Regla para compilar prueba
prueba: random_tree.cc
	$(CXX) random_tree.cc -o random.out

.PHONY: all clean cleanall prueba