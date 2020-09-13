// Declared inside class definition - no references?
#include <iostream>
using namespace std;

template <class T>
class Complex
{
private:
    T real, imaginary;

public:
    Complex(T rl, T im) {real = rl; imaginary = im;}
    T get_real() {return real;}
    T get_im() {return imaginary;}
};

// Declared outside class definition
#include <iostream>
using namespace std;

template <class T>
class Complex
{
private:
    T real, imaginary;

public:
    Complex(T&, T&);
    T& get_real();
    T& get_im();
};

template <class T>
Complex<T>::Complex(T& rl, T& im)
{
    real = rl; imaginary = im;
}

template <class T>
T& Complex<T>::get_real() 
{
    return real;
}

template <class T>
T& Complex<T>::get_im() 
{
    return imaginary;
}
