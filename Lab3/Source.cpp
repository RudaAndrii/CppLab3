#include <iostream>

using namespace std;

void selectionSort(int** matrix, int rows, int columns);
void f(int** matrix, int rows, int columns);
void F(int* arrayWithResults, int arrayLength);
void swap(int* a, int* b);
void showMatrix(int** matrix, int rows, int columns);

int main() {

	int ROWS, COLUMNS;
	cout << "Enter rows and columns amount: ";
	cin >> ROWS;
	COLUMNS = ROWS;

	int** matrix = new int*[ROWS];
	
	for (int i = 0; i < ROWS; i++) {
		matrix[i] = new int[COLUMNS];

		for (int j = 0; j < COLUMNS; j++) {
			cout << "Enter " << i+1 << ";" << j+1 << " matrix element: ";
			cin >> matrix[i][j];
		}
	}

	cout << "\nUnsorted matrix: \n";
	showMatrix(matrix, ROWS, COLUMNS);

	selectionSort(matrix, ROWS, COLUMNS);

	cout << "\nSorted matrix: \n";
	showMatrix(matrix, ROWS, COLUMNS);

	cout << "\n";

	f(matrix, ROWS, COLUMNS);
}

void showMatrix(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			
			printf("%d\t", matrix[i][j]);
			//cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}



void selectionSort(int** matrix, int rows, int columns) {
	for (int columnNumber = 0; columnNumber < columns; columnNumber++) {
		for (int j = 0; j < rows; j++) {
			int minElementIndex = j;
			for (int k = j; k < rows; k++) {
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

void swap(int* a, int* b) {
	int buff = *a;
	*a = *b;
	*b = buff;
}

void f(int** matrix, int rows, int columns) {
	int* results = new int[rows - 1];
	for (int i = 0; i < rows - 1; i++) {
		results[i] = 1;
		for (int k = 0; k < rows - 1 - i; k++) {
			results[i] *= matrix[i][k];
		}
		cout << "Line " << i + 1 << " product is " << results[i] << endl;
	}

	F(results, rows - 1);
}

void F(int* arrayWithResults, int arrayLength) {
	int sum = 0;
	for (int i = 0; i < arrayLength; i++) {
		sum += arrayWithResults[i];
	}

	cout << "Sum of all f-function values is: " << sum << endl;
}