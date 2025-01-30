#include <iostream>
#include <complex>

int main(){
    std::complex<double> z1(5,2);
    std::complex<double> z2(3,-1);
    
    /*
    double P1 = z1.real() * z2.real();
    double P2 = z1.imag() * z2.imag();
    double P3 = (z1.real() + z1.imag()) * (z2.real() + z2.imag());
    */

    double realResult = z1.real() * z2.real() - z1.imag() * z2.imag(); // P1 - P2
    double imagResult = (z1.real() + z1.imag()) * (z2.real() + z2.imag()) - realResult; // P3 - (P1 - P2)

    std::complex<double> result(realResult,imagResult);
    
    std::cout << result;
    return 0;
}

//average of 0.453