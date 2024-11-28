#include <vector>
#include <queue>
#include <iostream>
#include "Hora.hh"
#include "Caja.hh"

class Cjt_cajas {
public:
    // Constructor
    Cjt_cajas();

    void establecer_num_cajas(int n);

private:
    int num_cajas;
    std::vector<Caja> cajas;
}