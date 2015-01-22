/*
* MatrixMult.cpp
* By Pedro Garate on 01/21/2015
* Description: Computes the product of two matrices. The users
*              will provide the dimensionality of the two
*              matrices A and B, and subsequently their content.
*              At the end it prints out the multiplication
*              result.
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void multiply_matrices(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB);
int validInputSize(); // checks if input is correct (positive int)
int validInput(); // check if input is correct (int)

int main() {
	int a_rows, a_cols, b_rows, b_cols;
	cout << "MATRIX MULTIPLICATION:" << endl;

	cout << "Keep in mind that in order for the multiplication "
		<< "of matrices AxB to work, " << endl << "the number "
		<< "of columns in A has to be equal to the number of "
		<< "rows in B." << endl << endl; // disclaimer

	cout << "Enter the number of rows and columns for matrix A "
		<< "(separated by a space):" << endl;
	a_rows = validInputSize();
	a_cols = validInputSize();

	cout << "Matrix A has " << a_rows << " rows and " << a_cols
		<< " columns." << endl << endl;
	cout << "Matrix B has " << a_cols << " rows." << endl;
	cout << "Enter the number of columns for matrix B:" << endl;
	b_cols = validInputSize();
	b_rows = a_cols; // automatically set rows for B since matrix
	// multiplications requires columns of A and
	// rows of B to be the same.
	cout << "Matrix B has " << b_rows << " rows and " << b_cols
		<< " columns." << endl;

	vector<vector<int> > matrixA(a_rows);
	for (int i = 0; i < a_rows; i++)
		matrixA[i].resize(a_cols);//set up A

	vector<vector<int> > matrixB(b_rows);
	for (int i = 0; i < b_rows; i++)
		matrixB[i].resize(b_cols);//set up B

	cout << "\nNow enter the components of the matrices." << endl;
	cout << "For example in a 2x3 matrix, enter data as follows:" << endl;
	cout << "1 2 -3" << endl << "4 -5 6" << endl; //disclaimer

	cout << "\nEnter the numbers for matrix A row by row." << endl;
	for (int row = 0; row < a_rows; row++)
		for (int col = 0; col < a_cols; col++)
			matrixA[row][col] = validInput(); // input left to right,
	// row by row.

	cout << "\nEnter the numbers for matrix B row by row." << endl;
	for (int row = 0; row < b_rows; row++)
		for (int col = 0; col < b_cols; col++)
			matrixB[row][col] = validInput(); // input left to right,
	// row by row.

	cout << "\nThis is your matrix A:" << endl;
	for (int i = 0; i<a_rows; i++) {
		for (int j = 0; j<a_cols; j++){
			cout << matrixA[i][j] << "\t"; // show matrix A
		}// end for
		cout << endl;
	}// end for
	cout << "\nThis is your matrix B:" << endl;
	for (int i = 0; i<b_rows; i++) {
		for (int j = 0; j<b_cols; j++){
			cout << matrixB[i][j] << "\t"; // show matrix B
		}// end for
		cout << endl;
	}// end for

	multiply_matrices(matrixA, matrixB);
	return 0;
}// end main

void multiply_matrices(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB) {
	int rows = matrixA.size();
	int cols = matrixB[0].size();
	vector<vector<int> > result(rows);
	for (int i = 0; i < rows; i++)
		result[i].resize(cols); // set up matrix AxB

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (unsigned int k = 0; k < matrixA[0].size(); k++)
				result[i][j] += matrixA[i][k] * matrixB[k][j]; // <row of A>.<col of B>
			// dot product.
		}// end for
	}// end for

	cout << "\nThis is your result matrix AxB:" << endl;
	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++){
			cout << result[i][j] << "\t"; // show matrix AxB
		}// end for
		cout << endl;
	}// end for
}// end multiply_matrices

int validInputSize()
{
	int num;
	cin >> num;
	//detect if input isn't an int or less than 1.
	while (cin.fail() || num < 1)
	{
		// clear input and ignore what was entered
		// no matter the size.
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Bad entry.  Enter POSITIVE INTEGERS:\n";
		// get new input
		cin >> num;
	}// end while
	return num;
}// end validInputSize

int validInput()
{
	int num;
	cin >> num;
	// detect if input isn't an int.
	while (std::cin.fail())
	{
		// clear input and ignore what was entered
		// no matter the size.
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Bad entry.  Enter INTEGERS:\n";
		// get new input
		cin >> num;
	}// end while
	return num;
}// end validInput
