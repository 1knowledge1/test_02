#include<iostream>
#include <sstream>
using namespace std;

auto input(istream & stream,
	float ** & result_elements,
	int & result_rows,
	int & result_columns) -> istream &
{
	char symbol;
	bool success = true;
	int rows;
	int columns;

	if (stream >> rows && rows>0 && stream >> symbol && symbol == ',' && stream >> columns && columns>0);
	else {
		stream.setstate(std::ios::failbit);
		success = false;
		return stream;
	}

	string str;
	float ** elements;

	elements = new float *[rows];

	for (unsigned int i = 0; i < rows; ++i) {
		elements[i] = new float[columns];
		getline(stream, str);
		for (unsigned int j = 0; j < columns; ++j) {
			if (!(stream >> elements[i][j])) {
				stream.setstate(std::ios::failbit);
				success = false;
				return stream;
			}
		}
	}

	if (success) {
		result_elements = elements;
		result_rows = rows;
		result_columns = columns;
	}
	return stream;
}

int main() {
	
	int rows, columns, shift;
	float **elements;

	if (!(input(cin, elements, rows, columns))) {
		cout << "An error has occured while reading input data.\n";
		return 0;
	}
	
	if (!(cin >> shift) || (shift < 0)) {
		cout << "An error has occured while reading input data.\n";
		return 0;
	}

	int counter = 0;
	while (counter < shift) {
		for (int i = 1; i < rows; i++) {
			swap(elements[i - 1][0], elements[i][0]);
		}
		for (int i = 1; i < columns; i++) {
			swap(elements[rows - 1][i - 1], elements[rows - 1][i]);
		}
		for (int i = rows - 1; i > 0; i--) {

			swap(elements[i - 1][columns - 1], elements[i][columns - 1]);
		}
		for (int i = columns - 1; i > 1; i--) {
			swap(elements[0][i - 1], elements[0][i]);
		}
		counter++;
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			cout << elements[i][j] << ' ';
		}
		cout << '\n';
	}
	delete[] elements;
	return 0;
}
