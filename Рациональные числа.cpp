#include <iostream>

using namespace std;

class RationalNumbers {
public:
    RationalNumbers(int p_numerator, int p_denomintor) {
        numerator = p_numerator;
        denominator = p_denomintor;
    }
    RationalNumbers() {};
    void Print() {
        cout << numerator << "/" << denominator << endl;
    }
    void Sum(const RationalNumbers number) {
        numerator = numerator * number.denominator + denominator * number.numerator;
        denominator = denominator * number.denominator;
        ReduceFraction();
    }
    RationalNumbers Mult(const RationalNumbers number) const {
        RationalNumbers temp_number;
        temp_number.numerator = numerator * number.numerator;
        temp_number.denominator = denominator * number.denominator;
        temp_number.ReduceFraction();
        return temp_number;
    }
    
private:
    int numerator, denominator;
    void ReduceFraction() {
        int n = max(numerator, denominator);
        while (n != 1) {
            if (numerator % n == 0 && denominator % n == 0) {
                numerator = numerator / n;
                denominator = denominator / n;
            }
            n--;
        }
    }
};


int main()
{
    RationalNumbers number(2, 4);
    RationalNumbers number2(1, 3);
    RationalNumbers number3 = number.Mult(number2);
    number.Sum(number2);
    number3.Print();


}

