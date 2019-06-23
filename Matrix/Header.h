#pragma once

#include <vector>
#include <iostream>
#include <string>
#include<math.h>

class Matrix {
public:
	void getMatrixA();
	void initalizeMatrixA();
	void getMultiplyByScalar(double num);
	void getAddMatrix();
	void getSubtractMatrix();
	void getMultiplyMatrix(int input);
	void getTranspose();
	void getDeterminant();
private:
	void getMatrixB();
	void printMatrix(std::vector<std::vector<double>>);
	void sizeOfMatrix();
	std::vector <std::vector <double>> createMatrix();
	int row, col;
	std::vector<std::vector<double>> matrix;
	void multiplyByScalar(double num);
	void addMatrix();
	void subtractMatrix();
	void multiplyMatrix();
	void multiplyMatrix(int power);
	void transposeMatrix();
	double determinant(std::vector <std::vector <double>> matrix, int n);
};

Matrix matrix;
int input = 1;
std::vector <std::vector <double>> matrix1;
std::vector <std::vector <double>> matrix2;
void startProgram();
void menu();

