#include "Cjt_cajas.hh"

// Constructor
Cjt_cajas::Cjt_cajas() : num_cajas(0) {}

// Method to set the number of boxes
void Cjt_cajas::establecer_num_cajas(int n) {
    num_cajas = n;
    cajas.resize(n);
}