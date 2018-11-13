#include <iostream>

using namespace std;

void selectionSort(int** matrix, int matrixSize);
void calculateProductAboveAuxiliaryDiagonal(int** matrix, int matrixSize);
void sumOfArrayElements(int* arrayWithResults, int arrayLength);
void showMatrixToConsole(int** matrix, int matrixSize);

int main() {

	int matrixSize;
	cout << "Enter matrix size: ";
	cin >> matrixSize;

	int** matrix = new int*[matrixSize];
	
	for (int i = 0; i < matrixSize; i++) {
		matrix[i] = new int[matrixSize];

		for (int j = 0; j < matrixSize;j++) {
			cout << "Enter " << i+1 << ";" << j+1 << " matrix element: ";
			cin >> matrix[i][j];
		}
	}

	cout << "\nUnsorted matrix: \n";
	showMatrixToConsole(matrix, matrixSize);

	selectionSort(matrix, matrixSize);

	cout << "\nSorted matrix: \n";
	showMatrixToConsole(matrix, matrixSize);

	cout << "\n";

	calculateProductAboveAuxiliaryDiagonal(matrix, matrixSize);
}

void showMatrixToConsole(int** matrix, int matrixSize) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {

			
			printf("%d\t", matrix[i][j]);
			//cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}



void selectionSort(int** matrix, int matrixSize) {
	for (int columnNumber = 0; columnNumber < matrixSize; columnNumber++) {
		for (int j = 0; j < matrixSize; j++) {
			int minElementIndex = j;
			for (int k = j; k < matrixSize; k++) {
				if (matrix[k][columnNumber] < matrix[minElementIndex][columnNumber]) {
					minElementIndex = k;
				}
			}
			if (minElementIndex != j) {
				swap(matrix[j][columnNumber], matrix[minElementIndex][columnNumber]);
			}
		}
	}
}

void calculateProductAboveAuxiliaryDiagonal(int** matrix, int matrixSize) {
	int* results = new int[matrixSize - 1];
	for (int i = 0; i < matrixSize - 1; i++) {
		results[i] = 1;
		for (int k = 0; k < matrixSize - 1 - i; k++) {
			results[i] *= matrix[i][k];
		}
		cout << "Line " << i + 1 << " product is " << results[i] << endl;
	}

	sumOfArrayElements(results, matrixSize - 1);
}

void sumOfArrayElements(int* inputArray, int arrayLength) {
	int sum = 0;
	for (int i = 0; i < arrayLength; i++) {
		sum += inputArray[i];
	}

	cout << "Sum of all f-function values is: " << sum << endl;
}