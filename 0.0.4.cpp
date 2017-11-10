#include<iostream>
#include <sstream>
using namespace std;

int main() {
	
	int rows, columns;
	char sym;
	string str;

	getline(cin,str);
	istringstream stream(str);
	if (!(stream >> rows && rows > 0 && stream >> sym && sym == ',' && stream >> columns && columns > 0)) {
		cout << "An error has occurred while reading input data";
		return 0;
	}
	
	int ** elements = new int *[rows];
	for (int i = 0; i < rows; ++i) {
		elements[i] = new int[columns];
		for (int j = 0; j < columns; ++j) {
			elements[i][j] = 0;
		}
	}
	
	int k = 1, counter = 0;
	int max = columns*rows;
	while (k <= max) {
		for (int j = 0 + counter; j < columns-counter; j++)
			elements[0+counter][j] = k++;    
		if (k > max) break;
		for (int i = 1+counter; i < rows - counter; i++)
			elements[i][columns - 1- counter] = k++;
		if (k > max) break;
		for (int j = columns - 2- counter; j >= 0+ counter; j--)
			elements[rows - 1- counter][j] = k++; 
		if (k > max) break;
		for (int i = rows - 2- counter; i >= 1+ counter; i--)
			elements[i][0+ counter] = k++; 
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
