#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class RationalNumbers {
public:
    RationalNumbers(int numerator, int denomintor);
    RationalNumbers() {};
    void SetNumerator(int value) {
        numerator = value;
    }
    void SetDenominator(int value) {
        denominator = value;
    }
    int GetNumuerator() const {
        return numerator;
    }
    int GetDenominator() const{
        return denominator;
    }
    void Print() {
        cout << numerator << "/" << denominator << " ";
    }
    void Sum(const RationalNumbers number);
    RationalNumbers Mult(const RationalNumbers number) const;
    RationalNumbers operator+ (const RationalNumbers & number) const;
    RationalNumbers operator* (const RationalNumbers& number) const;
    RationalNumbers operator++ ();
    RationalNumbers operator++ (int);
    friend ostream& operator<<(ostream& out, const RationalNumbers& number);
    RationalNumbers operator+= (const RationalNumbers & number) {
        *this = *this + number;
        return *this + number;
    }
    RationalNumbers operator+= (const int number) {
        *this = *this + number;
        return *this;
    }
    RationalNumbers operator+(const int n);

    // сложение с числом и +=;

private:
    int numerator, denominator;
    void ReduceFraction();
};

istream& operator>>(istream& in, RationalNumbers& number);



