#include <iostream>
#include "cmplx.h"

#define V ComplexNumber::V
#define CN ComplexNumber


int main(){
   /* CN z1;
    std::cout << z1.argument() << std::endl;
    CN p_z1 = z1.polar_form();
    V(p_z1);*/
    CN z2(4,0), p_z2;
    p_z2 = z2.polar_form();
    V(z2);
    V(p_z2);

//    z1.n_roots(3);
   // CN z3 = z1+z2;
   // V(z3);

    z2.n_roots(1000);



}


