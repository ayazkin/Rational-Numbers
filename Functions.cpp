#include "Functions.h"

RationalNumbers* GetNumbers(ifstream& in, int& arraySize) {
    int numerator, denominator;
    in >> arraySize;
    RationalNumbers* array = new RationalNumbers[arraySize];
    for (int i = 0; i < arraySize; i++) {
        in >> array[i];
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
        RationalNumbers temp = array1[i]*array2[i];
        result += temp;
    }
    return result;
}

RationalNumbers** CreateMatrix(ifstream& in, int& rows, int& cols) {
    in >> rows >> cols;
    RationalNumbers** matrix = new RationalNumbers * [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new RationalNumbers[cols];
        for (int j = 0; j < cols; j++) {
            in >> matrix[i][j];
        }
    }
    return matrix;
}

RationalNumbers** MultMatrix(RationalNumbers** matrix1, int rows1, int cols1, RationalNumbers** matrix2, int rows2, int cols2) {
    RationalNumbers** result = new RationalNumbers * [rows1];
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
                result[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    return result;
}

void PrintMatrix(RationalNumbers** matrix, int rows, int cols) {
    cout << "Матрица" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
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
        result = result + matrix[i][i];
    }
    return result;
}

void deleteMatrix(RationalNumbers** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


