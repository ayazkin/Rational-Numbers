#pragma once
#include <iostream>
#include <fstream>
#include "RationalNumbers.h"

using namespace std;

RationalNumbers* GetNumbers(ifstream& in, int& arraySize);

RationalNumbers ScolarMult(RationalNumbers* array1, RationalNumbers* array2, int n1, int n2);

RationalNumbers** CreateMatrix(ifstream& in, int& rows, int& cols);

RationalNumbers** MultMatrix(RationalNumbers** matrix1, int rows1, int cols1, RationalNumbers** matrix2, int rows2, int cols2);

void PrintMatrix(RationalNumbers** matrix, int rows, int cols);

RationalNumbers Sledovanie(RationalNumbers** matrix, int rows, int cols);

void deleteMatrix(RationalNumbers** matrix, int rows);

istream& operator>> (istream& in, RationalNumbers& number);

ostream& operator<< (ostream& out, const RationalNumbers& number);
