#include <iostream>
#include <fstream>

using namespace std;

class RationalNumbers {
public:
    RationalNumbers(int p_numerator, int p_denomintor) {
        numerator = p_numerator;
        denominator = p_denomintor;
    }
    RationalNumbers() {};
    void SetNumerator(int value) {
        numerator = value;
    }
    void SetDenominator(int value) {
        denominator = value;
    }
    void Print() {
        cout << numerator << "/" << denominator << " ";
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
        int n = min(numerator, denominator);
        while (n != 0) {
            if (numerator % n == 0 && denominator % n == 0) {
                numerator = numerator / n;
                denominator = denominator / n;
            }
            n--;
        }
    }
};

RationalNumbers* GetNumbers(ifstream & in, int& arraySize) {
    int numerator, denominator;
    in >> arraySize;
    RationalNumbers* array = new RationalNumbers[arraySize];
    for (int i = 0; i < arraySize; i++) {
        in >> numerator >> denominator;
        array[i].SetNumerator(numerator);
        array[i].SetDenominator(denominator);
    }
    return array;
}

RationalNumbers ScolarMult(RationalNumbers* array1, RationalNumbers* array2, int n1, int n2) {
    if (n1 != n2) {
        cout << "Векторы разной длины :( " << endl;
        exit(-1);
    }
    RationalNumbers result(0, 1);
    for (int i = 0; i < n1; i++) {
        RationalNumbers temp = array1[i].Mult(array2[i]);
        result.Sum(temp);
    }
    return result;
}
RationalNumbers** CreateMatrix(ifstream& in, int& rows, int& cols) {
    in >> rows >> cols;
    RationalNumbers** matrix = new RationalNumbers* [rows];
    for (int i = 0; i < rows; ++i) {
        int num, den;
        matrix[i] = new RationalNumbers[cols];
        for (int j = 0; j < cols; j++) {
            in >> num >> den;
            matrix[i][j] = RationalNumbers(num, den);
        }
    }
    return matrix;
}

RationalNumbers** MultMatrix(RationalNumbers** matrix1, int rows1, int cols1, RationalNumbers** matrix2, int rows2, int cols2) {
    RationalNumbers** result = new RationalNumbers*[rows1];
    for (int i = 0; i < rows1; i++) {
        result[i] = new RationalNumbers[cols2];
        for (int j = 0; j < cols2; j++) {
            result[i][j] = RationalNumbers(0, 1);
        }
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = RationalNumbers(0, 1);
            for (int k = 0; k < rows2; k++)
            {
                result[i][j].Sum(matrix1[i][k].Mult(matrix2[k][j]));
            }
        }
    }
    return result;
}

void PrintMatrix(RationalNumbers** matrix, int rows, int cols) {
    cout << "Матрица" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j].Print();
        }
        cout << endl;
    }
}

RationalNumbers Sledovanie(RationalNumbers** matrix, int rows, int cols) {
    if (rows != cols) {
        cout << "Следование возможно только для квадратных матриц" << endl;
        exit(-1);
    }
    RationalNumbers result(0, 1);
    for (int i = 0; i < rows; i++) {
        result.Sum(matrix[i][i]);
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    RationalNumbers number(2, 4);
    RationalNumbers number2(1, 3);
    RationalNumbers number3 = number.Mult(number2);
    number.Sum(number2);
    cout << "Результат перемножения: ";
    number3.Print();
    cout << endl;

    ifstream in("in.txt");
    int array1_length;
    RationalNumbers* array1 = GetNumbers(in, array1_length);
    for (int i = 0; i < array1_length; i++) {
        array1[i].Print();
        cout << endl;
    }
    in.close();
    cout << "---------------------" << endl;
    ifstream in2("in2.txt");
    int array2_length;
    RationalNumbers* array2 = GetNumbers(in2, array2_length);
    for (int i = 0; i < array2_length; i++) {
        array2[i].Print();
        cout << endl;
    }
    cout << "---------------------" << endl;
    in2.close();

    RationalNumbers scalaredNumber = ScolarMult(array1, array2, array1_length, array2_length);
    cout << "Скалярное произведение: ";
    scalaredNumber.Print();  // подсчитно вручную, результат должен быть 63/80
    cout << endl;


    cout << "Первая матрица создана со значениями" << endl;
    int rows1, cols1;
    ifstream in_matrix1("in_matrix.txt");
    RationalNumbers** matrix1 = CreateMatrix(in_matrix1, rows1, cols1);
    PrintMatrix(matrix1, rows1, cols1);
    
    cout << "Вторая матрица создана со значениями" << endl;
    int rows2, cols2;
    ifstream in_matrix2("in_matrix2.txt");
    RationalNumbers** matrix2 = CreateMatrix(in_matrix2, rows2, cols2);
    PrintMatrix(matrix2, rows2, cols2);

    RationalNumbers** multed_matrix = MultMatrix(matrix1, rows1, cols1, matrix2, rows2, cols2); 
    PrintMatrix(multed_matrix, rows1, cols2); 

    RationalNumbers sledovanieResult = Sledovanie(multed_matrix, rows1, cols2);
    sledovanieResult.Print();

}

// TO DO:
// 2ой проект это сделать через указатели на объекты

