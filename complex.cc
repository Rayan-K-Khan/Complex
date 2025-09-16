/*complex.h*/
#ifndef Complex_H
#define Complex_H

#include <iostream>
#include <cmath>

using std::ostream;
using std::cout;
using std::endl;

struct Complex {

    Complex(double = 0, double = 0);

    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const Complex &) const;
    Complex operator/(const Complex &) const;

    Complex operator+(double) const;
    Complex operator-(double) const;
    Complex operator*(double) const;
    Complex operator/(double) const;

    friend Complex operator+(double, const Complex &);
    friend Complex operator-(double, const Complex &);
    friend Complex operator*(double, const Complex &);
    friend Complex operator/(double, const Complex &);

    friend ostream &operator<<(ostream &, const Complex &);

    double abs() const
    {
        return std::sqrt(re*re+im*im);
    }

    Complex conj() const
    {
        return Complex(re, -im);
    }

    double real() const
    {
        return re;
    }

    double imag() const
    {
        return im;
    }

private:

    double re;
    double im;
};

#endif
/*complex.cc*/

Complex::Complex(double re, double im) : re(re), im(im) {}

//add
Complex Complex::operator+(const Complex &o) const {

    return Complex(re + o.re, im + o.im);
}

Complex Complex::operator+(double n) const {

    return Complex(re+n, im);
}

Complex operator+(double n, const Complex &o) {

    return o + n;
}

//sub
Complex Complex::operator-(const Complex &o) const {

    return Complex(re-o.re, im-o.im);
}

Complex Complex::operator-(double n) const {

    return Complex(re-n, im);
}

Complex operator-(double n, const Complex &o) {

    return Complex(n) - o;
}

//mul
Complex Complex::operator*(const Complex &o) const {

    return Complex(re*o.re - im*o.im, re*o.im + im*o.re);
}

Complex Complex::operator*(double n) const {

    return Complex(re*n, im*n);
}

Complex operator*(double n, const Complex &o) {

    return o * n;
}

//div
Complex Complex::operator/(const Complex &o) const {

    double d = o.re*o.re + o.im*o.im;
    return Complex((re*o.re + im*o.im)/d, (im*o.re - re*o.im)/d);
}

Complex Complex::operator/(double n) const {

    return Complex(re/n, im/n);
}

Complex operator/(double n, const Complex &o) {

    return Complex(n) / o;
}

//print
ostream &operator<<(ostream &out, const Complex &o) {

    if (o.im<0)
    {
        out << '(' << o.re << " - " << -o.im << "i)";
        return out;
    }

    out << '(' << o.re << " + " << o.im << "i)";
    return out;
}

/*main.cc*/
int main(void) {

    Complex a(3,-4);
    Complex b(1,1);
    Complex c = b.conj();

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "\n";

    cout << "Re("<<a<<") = " << a.real() << " Im("<<a<<") = " << a.imag() << endl;
    cout << "\n";

    cout << a << " + " << b << " = " << a+b << endl;
    cout << c << " + " << 3 << " = " << c+3 << endl;
    cout << 2 << " + " << a << " = " << 2+a << endl;
    cout << "\n";

    cout << a << " - " << b << " = " << a-b << endl;
    cout << c << " - " << 3 << " = " << c-3 << endl;
    cout << 2 << " - " << a << " = " << 2-a << endl;
    cout << "\n";

    cout << b << " * " << c << " = " << b*c << endl;
    cout << c << " * " << 3 << " = " << c*3 << endl;
    cout << 2 << " * " << a << " = " << 2*a << endl;
    cout << "\n";

    cout << b << " / " << c << " = " << b/c << endl;
    cout << c << " / " << 2 << " = " << c/2 << endl;
    cout << 2 << " / " << a << " = " << 2/a << endl;
    cout << "\n";

    cout << "|a| = " << a.abs() << endl;
    cout << "|b| = " << b.abs() << endl;
    cout << "|c| = " << c.abs() << endl;
}