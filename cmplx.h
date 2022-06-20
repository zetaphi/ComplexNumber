#pragma once

class ComplexNumber{
private:
    int real, imgnry;

public:
    ComplexNumber() : real(0), imgnry(0) {}
    ComplexNumber(int r, int i) : real(r), imgnry(i) {}
    ComplexNumber(const ComplexNumber* other) { // for +, -, * and whenever function return ComplexNumber
        this -> real = other -> real;
        this -> imgnry = other -> imgnry;
        delete other;
    }
    ComplexNumber(ComplexNumber& other){ //for assigning from other
        this -> real = other.real;
        this -> imgnry = other.imgnry;
    }
    void set_real(int r) { this -> real = r; }
    void set_imgnry(int i) { this -> imgnry = i; }
    int get_real() const { return this -> real; }
    int get_imgnry() const { return this -> imgnry;  }
    const ComplexNumber* operator+(ComplexNumber& other) const {
        return new ComplexNumber( this -> real + other.real, this -> imgnry  + other.imgnry);
    }
    const ComplexNumber* operator-(ComplexNumber& other) const {
        return new ComplexNumber( this -> real - other.real, this -> imgnry - other.imgnry);
    }

public:

    static void V(ComplexNumber& instance){
        std::cout << "real : " << instance.get_real() << " imgnry : " << instance.get_imgnry() << std::endl;

    }

};

