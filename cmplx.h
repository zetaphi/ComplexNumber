#pragma once

#include <math.h>
#include <vector>
#include <fstream>

 // recommended
 // #define CN ComplexNumber
 // #define V ComplexNumber::View
// "INITIALIZE FIRST USE LATER"

class ComplexNumber{
private:
    float real, imgnry;

public:
    ComplexNumber() : real(0), imgnry(0) {}
    ComplexNumber(float r, float i) : real(r), imgnry(i) {}

    ComplexNumber(ComplexNumber& other){ //for assigning from other
        this -> real = other.real;
        this -> imgnry = other.imgnry;
    }
    void set_real(float r) { this -> real = r; }
    void set_imgnry(float i) { this -> imgnry = i; }
    float get_real() const { return this -> real; }
    float get_imgnry() const { return this -> imgnry;  }


    ComplexNumber operator+(ComplexNumber& other) const {
        return ComplexNumber((*this).real + other.real, (*this).imgnry + other.imgnry);
    }

    ComplexNumber operator-(ComplexNumber& other) const {
        return ComplexNumber((*this).real - other.real, (*this).imgnry - other.imgnry);
    }

    ComplexNumber operator*(ComplexNumber& other) const {
        return ComplexNumber((*this).real*other.real - (*this).imgnry*other.imgnry,
                            (*this).imgnry*other.real + (*this).real*other.imgnry);
    }

    bool operator==(ComplexNumber& other) const {
        return ((*this).real == other.real) && ((*this).imgnry == other.imgnry);
    }

    ComplexNumber conj() const {
        return ComplexNumber( (*this).real, -(*this).imgnry );
    }

    bool orgin() const {
        return ( this -> real == 0 && this -> imgnry == 0 );
    }

    double argument(){
        if(this -> orgin()) return 2*M_PI; //origin
        else if( this -> real != 0) {
            double arg = atan(this -> imgnry / this -> real);
            if( this -> real > 0 ) return arg;
            if( this -> real < 0 ){
                if ( this -> imgnry > 0 ) return arg  + M_PI;
                else  return arg - M_PI;
            }
        } else {
            if( this -> imgnry > 0) return M_PI/2;
            else return -M_PI/2;
        }
    }

    ComplexNumber polar_form(){
        ComplexNumber z;
        if ( this -> orgin() ) return z;
        else {
            double theta = this -> argument();

            double magnitude = ComplexNumber::Magnitude((*this));
            z.set_real( magnitude *  cos(theta) );
            z.set_imgnry( magnitude * sin(theta) );
            return z;
        }
    }

    void n_roots(unsigned int n){
        std::vector<ComplexNumber*> roots;
        roots.reserve(n);
        double theta = (*this).argument();
        double magn = ComplexNumber::Magnitude(*this);
        double root_mgn = pow(magn, 1.0/n);
        for(int i=0; i<n; i++){
            double theta_ = (theta + 2*i*M_PI)/n;
            roots.emplace_back( new ComplexNumber(root_mgn * cos(theta_), root_mgn * sin(theta_)) );
        }
        ComplexNumber::save_data("roots.txt", roots);
        for(auto i = roots.begin(); i!=roots.end(); i++){
            free(*i);
        }
    }

public:

    static void V( ComplexNumber& instance) {
        std::cout << "real : " << instance.get_real() << " imgnry : " << instance.get_imgnry() << std::endl;
    }

    static double  Magnitude( ComplexNumber& instance){
        return sqrt( ((instance.conj())*instance).real  );
        //return sqrt( instance.real * instance.real + instance.imgnry * instance.imgnry );
    }


    static void save_data(const std::string& filename, const std::vector<ComplexNumber*>& data){
        std::fstream file;
        file.open(filename, std::ios::out | std::ios::trunc);

        if( !file ){
            std::cout << "FILE NOT CREATED" << std::endl;
            return;
        }
        for(int i=0; i < data.size(); i++){
           // file << i << " " <<( data[i] -> get_real() )<< " " << ( data[i] -> get_imgnry() ) << std::end;
            file << i << ".    " << data[i] -> get_real() << "     " << data[i] -> get_imgnry() << "i" << std::endl;

        }
    }
};

