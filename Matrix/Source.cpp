/*The Ulitmate Matrix Calculator. C++ Console application performing various matrix operations. By: Christopher Lee. Copyright 2019*/

#include "Header.h"

using namespace std;

int main() {
	startProgram();
	menu();
	system("pause");
	return 0;
}

//initialize the program
void startProgram() {
	cout << "Welcome to the Ultimate Matrix Calculator" << endl << endl;
	cout << "Begin by initializing your Matrix A" << endl << endl;
	matrix.initalizeMatrixA();
	matrix.getMatrixA();
}

//the core loop of the program
void menu() {
	while (input != 0) {
		cout << endl << "1 - Print Matrix A" << endl << "2 - Change Matrix A" << endl << "3 - Multiply Matrix A by a scalar" << endl << "4 - Add Matrix A to a Matrix B" << endl << "5 - Subtract a Matrix B from Matrix A" << endl << "6 - Multiply Matrix A by Matrix B" << endl << "7 - Raise Matrix A to a power" << endl << "8 - Transpose of Matrix A" << endl << "9 - Determinant of Matrix A" << endl;
		cout << "0 - Quit Program" << endl << endl;
		cout << "Please input your choice: " << endl;
		cin >> input;

		if (input == 1) {
			matrix.getMatrixA();
		}
		else if (input == 2) {
			matrix.initalizeMatrixA();
			matrix.getMatrixA();
		}
		else if (input == 3) {
			int num;
			cout << endl << "Input the scalar to multiply Matrix A by:" << endl;
			cin >> num;
			matrix.getMultiplyByScalar(num);
			cout << endl << "The result of the scalar " << num << " multiplied by the Matrix A: " << endl;
			matrix.getMatrixA();
		}
		else if (input == 4) {
			matrix.getAddMatrix();
		}
		else if (input == 5) {
			matrix.getSubtractMatrix();
		}
		else if (input == 6) {
			matrix.getMultiplyMatrix(input);
		}
		else if (input == 7) {
			matrix.getMultiplyMatrix(input);
		}
		else if (input == 8) {
			matrix.getTranspose();
		}
		else if (input == 9) {
			matrix.getDeterminant();
		}
	}
}
void Matrix::getMatrixA() {
	cout << endl << "Matrix A: " << endl;
	printMatrix(matrix1);
}
void Matrix::getMatrixB() {
	cout << endl << "Matrix B: " << endl;
	printMatrix(matrix2);
}
void Matrix::getAddMatrix() {
	addMatrix();
}
void Matrix::getSubtractMatrix() {
	subtractMatrix();
}
void Matrix::getMultiplyByScalar(double num) {
	multiplyByScalar(num);
}
//power of Matrix A
void Matrix::getMultiplyMatrix(int input) {
	if (input == 6) {
		multiplyMatrix();
	}
	else {
		int power = 1;
		cout << "Raise to the matrix A to the power of: " << endl;
		cin >> power;
		multiplyMatrix(power);
	}
}
//trnaspose of the matrix A
void Matrix::getTranspose() {
	transposeMatrix();
	getMatrixA();
}
//get the determinant
void Matrix::getDeterminant() {
	if (matrix1.size() == matrix1[0].size()) {
		int n = matrix1.size();
		double determinant1 = determinant(matrix1, matrix1.size());
		cout << endl << "The determinant of Matrix A: " << determinant(matrix1, n) << endl;
	}
	else {
		cout << endl << "Matrix is not square. Cannot compute determinant." << endl;
	}
}
//create Matrix A
void Matrix::initalizeMatrixA(){
	sizeOfMatrix();
	matrix = createMatrix();
	matrix1.swap(matrix);
}
//compute the determinant
double Matrix::determinant(vector <vector <double>> matrix, int n) {
	vector <vector <double>> matrix1;
	matrix1.resize(n, vector<double>(n, 0));
	double determinant = 0;
	//test case 1 and test case 2
	if (n == 1) {
		return determinant = matrix[0][0];
	}
	else if (n == 2) {
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}
	//computing determinant for nxn matrix where n > 2
	else {
		// creating coffactor matrix
		for (int i = 0; i < n; i++) {
			int l = 0;
			for (int j = 1; j < n; j++) {
				int m = 0;
				for (int k = 0; k < n; k++) {
					if (k == i)
					continue;
					matrix1[l][m] = matrix[j][k];
					m++;
				}
				l++;
			}
			//recusive statement
			determinant = determinant + (pow(-1, i) * matrix[0][i] * Matrix::determinant(matrix1, n - 1));
		}		
	}
	return determinant;
}
//add 2 matrices of the same size
void Matrix::addMatrix() {
		cout << endl << "Initialize Matrix B:" << endl;
		sizeOfMatrix();
		//cout << matrix1.size() << " " << matrix.size() << endl << matrix1[0].size() << " " << matrix[0].size() << endl;
		//check if matrices are both the same size
		if (matrix.size() == matrix1.size() && matrix[0].size() == matrix1[0].size()) {
			createMatrix();
			matrix2.swap(matrix);
			for (int i = 0; i < matrix1.size(); i++) {
				for (int j = 0; j < matrix1[i].size(); j++) {
					matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
				}
			}
			getMatrixB();
			cout << endl << "The result of the Matrix A added to the Matrix B: " << endl;
			printMatrix(matrix1);
			cout << endl;
		}
		//if the matrix is of the wrong size then we reinitialize the temporary matrix and return to the beginning
		else {
			matrix2.swap(matrix);
			cout << endl << "Matrix size mismatch. Please try again." << endl;
		}
}
//subtract 2 matrices of the same size
void Matrix::subtractMatrix() {
	cout << endl << "Initialize Matrix B:" << endl;
	sizeOfMatrix();
	//cout << matrix1.size() << " " << row << endl << matrix1[0].size() << " " << col << endl;
	//check if matrices are both the same size
	if (matrix1.size() == matrix.size() && matrix1[0].size() == matrix[0].size()) {
		createMatrix();
		matrix2.swap(matrix);
		for (int i = 0; i < matrix1.size(); i++) {
			for (int j = 0; j < matrix1[i].size(); j++) {
				matrix1[i][j] = matrix1[i][j] - matrix2[i][j];
			}
		}
		getMatrixB();
		cout << endl << "The result of the Matrix B subtracted from the Matrix A: " << endl;
		printMatrix(matrix1);
		cout << endl;
	}
	//if the matrix is of the wrong size then we reinitialize the temporary matrix and return to the beginning
	else {
		matrix2.swap(matrix);
		cout << endl << "Matrix size mismatch. Please try again." << endl;
	}
}
//multiplication of 2 matrices of varying size
void Matrix::multiplyMatrix() {
	cout << endl << "Initialize Matrix B:" << endl;
	sizeOfMatrix();
	//cout << matrix1.size() << " " << row << endl << matrix1[0].size() << " " << col << endl;
	//check if matrix B is the correct size i.e. col(A)=row(B)
	if (matrix1[0].size() == matrix.size()) {
		createMatrix();
		matrix2.swap(matrix);
		matrix.resize(matrix1.size(), vector<double>(matrix2[0].size(), 0)); //size resulting matrix based on the rows of first and col if second
		int i, j, k;
		for (i = 0; i < matrix.size(); i++)
		{
			for (j = 0; j < matrix[i].size(); j++)
			{
				matrix[i][j] = 0;//reinitialize matrix values that haven't been computed
				for (k = 0; k < matrix1[i].size(); k++)
					matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
		matrix1.swap(matrix);
		getMatrixB();
		cout << endl << "The result of the Matrix A multiplied by the Matrix B: " << endl;
		printMatrix(matrix1);
		cout << endl;
	}
	//if the matrix is of the wrong size then we reinitialize the temporary matrix and return to the beginning
	else {
		matrix2.swap(matrix);
		cout << endl << "Matrix size mismatch. Please try again." << endl;
	}
}
//power of a matrix of varying size
void Matrix::multiplyMatrix(int power) {
	vector<vector<double>> tempMatrix = matrix1;
	//cout << matrix1.size() << " " << row << endl << matrix1[0].size() << " " << col << endl;
	matrix.clear();
	matrix.resize(matrix1.size(), vector<double>(matrix1[0].size(), 0));
	if (matrix1[0].size() == matrix.size()) {
		int i, j, k;
		for (int l = 1; l < power; l++) {
			for (i = 0; i < matrix.size(); i++)
			{
				for (j = 0; j < matrix[i].size(); j++)
				{
					matrix[i][j] = 0;//reinitialize matrix values that haven't been computed
					for (k = 0; k < matrix1[i].size(); k++)
						matrix[i][j] += matrix1[i][k] * tempMatrix[k][j];
				}
			}
			matrix1 = matrix;
		}
		matrix1.swap(matrix);
		cout << endl << "The result of the Matrix A to the power of " << power << " is:" << endl;
		printMatrix(matrix1);
		cout << endl;
	}
	else {
		cout << endl << "Matrix size mismatch. Please try again." << endl;
	}
}
//output any Matrix
void Matrix::printMatrix(vector<vector<double>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";	
		}
		cout << endl;
	}
}
//initialize the size of the matrix before inputing values
void Matrix::sizeOfMatrix() {
	bool valid = false;
	do {
		matrix.clear();
		cout << endl << "Indicate the number of rows and then number of coloumns seperated by a space:" << endl;
		cin >> row >> col;
		if (row > 0 && col > 0) {
			matrix.resize(row, vector<double>(col, 0));
			valid = true;
			break;
		}
		cout << endl << "Invalid matrix row or column entry." << endl;
	} while (valid == false);
}

//creates a matrix based on the size in the sizeOfMatrix function
vector <vector <double>> Matrix::createMatrix() {
		double num;
		cout << endl << "Enter the " << row*col << " numbers of the " << row << " x " << col << " matrix seperated by spaces:" << endl;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				cin >> num;
				matrix[i][j] = num;
			}
		}
	return matrix;
}
//multiply a scalar, inputted by the user, by matrix A
void Matrix::multiplyByScalar(double num) {
	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1[i].size(); j++) {
			matrix1[i][j] = num * matrix1[i][j];
		}
	}
}
void Matrix::transposeMatrix() {
	int k = 0;
	matrix.clear();
	matrix.resize(matrix1[0].size(), vector<double>(matrix1.size(), 0));
	try
	{
		for (int i = 0; i < matrix1.size(); i++) {
			for (int j = 0; j < matrix.at(i).size(); j++) {
				matrix.at(i).at(j)= 0;//reinitialize matrix values that haven't been computed
				for (k = 0; k < matrix1.at(i).size(); k++)
					matrix.at(k).at(j) = matrix1.at(j).at(k);
			}
		}
	}
	catch (std::out_of_range outOfRange) {

	}
	matrix1.swap(matrix);
}


