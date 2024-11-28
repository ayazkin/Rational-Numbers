#include <iostream>
#include <fstream>
#include "RationalNumbers.h"
#include "Functions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    RationalNumbers number(2, 4);
    RationalNumbers number2(1, 3);
    RationalNumbers number3 = number * number2;
    number = number + number2;
    cout << "Результат перемножения: ";
    cout << number3 << " ";
    cout << endl << "Сумма: ";
    cout << number << " ";
    cout << endl << "Префикс: ";
    cout << ++number << " ";
    cout << number << " ";
    cout << endl << "Постфикс: ";
    cout << number++ << " ";
    int n = 2;
    number += 2;
    cout << endl << "Сложение с числом: ";
    cout << number << endl;

    ifstream in("in.txt");
    int array1_length;
    RationalNumbers* array1 = GetNumbers(in, array1_length);
    for (int i = 0; i < array1_length; i++) {
        cout << array1[i] << endl;
    }
    in.close();
    cout << "---------------------" << endl;
    ifstream in2("in2.txt");
    int array2_length;
    RationalNumbers* array2 = GetNumbers(in2, array2_length);
    for (int i = 0; i < array2_length; i++) {
        cout << array2[i] << endl;
    }
    cout << "---------------------" << endl;
    in2.close();

    RationalNumbers scalaredNumber = ScolarMult(array1, array2, array1_length, array2_length);
    cout << "Скалярное произведение: ";
    cout << scalaredNumber << endl;  // результат должен быть 63/80

    delete[] array1;
    delete[] array2;

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

    deleteMatrix(matrix1, cols1);
    deleteMatrix(matrix2, cols2);
    deleteMatrix(multed_matrix, rows2);
}