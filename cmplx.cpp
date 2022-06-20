#include <iostream>
#include "cmplx.h"

#define V ComplexNumber::V

int main(){
    ComplexNumber c1;
    V(c1);
    ComplexNumber c2(1,1);
    V(c2);
    c2.set_imgnry(2);
    c2.set_real(2);
    V(c2);
    ComplexNumber c3(3,-2);
    ComplexNumber c4 = c2 + c3;
    V(c4);
}


