#include "RationalNumbers.h"

    RationalNumbers::RationalNumbers(int numerator, int denomintor) {
        this->numerator = numerator;
        this->denominator = denomintor;
    }
    void RationalNumbers::Sum(const RationalNumbers number) {
        numerator = numerator * number.denominator + denominator * number.numerator;
        denominator = denominator * number.denominator;
        ReduceFraction();
    }
    RationalNumbers RationalNumbers::Mult(const RationalNumbers number) const {
        RationalNumbers temp_number;
        temp_number.numerator = numerator * number.numerator;
        temp_number.denominator = denominator * number.denominator;
        temp_number.ReduceFraction();
        return temp_number;
    }
    RationalNumbers RationalNumbers::operator+(const RationalNumbers& number) const 
    {
        RationalNumbers temp(*this);
        temp.numerator = temp.numerator * number.denominator + temp.denominator * number.numerator;
        temp.denominator = temp.denominator * number.denominator;
        temp.ReduceFraction();
        return temp;
    }
    RationalNumbers RationalNumbers::operator+(const int n)
    {
        RationalNumbers number_n(n, 1);
        return *this + number_n;
    }

    RationalNumbers RationalNumbers::operator*(const RationalNumbers& number) const
    {
        RationalNumbers temp_number;
        temp_number.numerator = numerator * number.numerator;
        temp_number.denominator = denominator * number.denominator;
        temp_number.ReduceFraction();
        return temp_number;
    }
    RationalNumbers RationalNumbers::operator++()
    {
        *this = *this + RationalNumbers(1, 1);
        return *this;
    }
    RationalNumbers RationalNumbers::operator++ (int)
    {
        RationalNumbers copy(*this);
        ++(*this);
        return copy;
    }

    void RationalNumbers::ReduceFraction() {
        int n = min(numerator, denominator);
        while (n != 0) {
            if (numerator % n == 0 && denominator % n == 0) {
                numerator = numerator / n;
                denominator = denominator / n;
            }
            n--;
        }
    }
    istream& operator>>(istream& in, RationalNumbers& number) {
        int numerator, denominator;
        in >> numerator >> denominator;
        number.SetNumerator(numerator);
        number.SetDenominator(denominator);
        return in;
    }

    ostream& operator<<(ostream& out, const RationalNumbers& number)
    {
        out << number.numerator << "/" << number.denominator;
        return out;
    }