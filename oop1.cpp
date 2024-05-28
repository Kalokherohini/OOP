#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloaded operator+ to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded operator* to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        return Complex(
            (real * other.real) - (imag * other.imag),
            (real * other.imag) + (imag * other.real)
        );
    }

    // Overloaded << to print a complex number
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }

    // Overloaded >> to read a complex number
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    Complex c1, c2;
    
    cout << "Enter first complex number:\n";
    cin >> c1;
    
    cout << "Enter second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "First Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}

