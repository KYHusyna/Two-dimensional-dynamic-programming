#include <iostream>
#include <ctime>

using namespace std;

void secondLVL(int steps) {
	srand(time(NULL));

	cout << endl;
	cout << " ----second Level----" << endl;

	cout << endl;
	int row = 0, columns = 0;
	cout << "Enter row value: " << endl;
	cin >> row;
	cout << "Enter columns value: " << endl;
	cin >> columns;
	if ((row < 1 || columns < 1) || (row == 1 && row == columns))
	{
		cout << -1 << endl;
		return;
	}
	if (row == columns) {
		cout << "Wrong! array must be rectangle" << endl;
		return;
	}
	cout << endl;

	if (columns > row)
		swap(row, columns);

	long long znum = 1, ways = 1;
	for (int i = 0; i < columns; i++) {
		ways = ways * (i + columns);
		if (ways % znum == 0) {
			ways = ways / znum;
			znum++;
		}
	}
	cout << endl;
	cout << "ways= " << ways << endl;
}

static int minimum(int min, int s) {
	if (min > s)
		min = s;
	return min;
}

void third(int path) {

	int n, m, row, columns, min = 0;
	cout << "----third level----" << endl;
A:
	cout << "Enter row value: " << endl;
	cin >> row;
	cout << "Enter columns value: " << endl;
	cin >> columns;

	if ((row < 1 || columns < 1) || (row == 1 && row == columns))
	{
		cout << -1 << endl;
		return;
	}
	if (row == columns) {
		cout << "Wrong! array must be rectangle" << endl;
		goto A;
	}
	cout << "take array " << endl;


	int** pathArr = new int* [row];
	int** arr = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[columns];
		pathArr[i] = new int[columns];
	}

	srand(time(0));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < columns; j++) {

			arr[i][j] = rand() % 10 + 1;
			cout << arr[i][j] << " ";
			pathArr[i][j] = 0;
		}
		cout << endl;
	}


	int sum = 0;
	int i = row - 1, j = columns - 1;
	pathArr[i][j] = arr[i][j];
	while ((i >= 0 && j >= 0)) {
		if (i == j && j == 0)
			break;
		if (i == 0 && j > 0)
			j--;
		else if (j == 0 && i > 0)
			i--;
		else {
			if (arr[i][j - 1] < arr[i - 1][j - 1]) {
				if (arr[i][j - 1] < arr[i - 1][j]) {
					if (j != 0)
						j -= 1;
				}
				else {
					if (i != 0)
						i -= 1;
					if (j != 0)
						j -= 1;
				}
			}
			else
			{
				if (arr[i - 1][j - 1] < arr[i - 1][j]) {
					if (i != 0)
						i -= 1;
					if (j != 0)
						j -= 1;
				}
				else {
					if (i != 0)
						i -= 1;
				}
			}
		}
		pathArr[i][j] = arr[i][j];
		sum += arr[i][j];
	}



	cout << "sum of path=" << sum << endl;

	cout << "Path: " << endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < columns; j++) {
			cout << pathArr[i][j] << " ";
		}
		cout << endl;
	}

}
int main()
{
	int restart = 0;
	int  steps = 0, path = 0;
A:
	secondLVL(steps);
	cout << "To restart enter: 0" << endl;
	cin >> restart;
	if (restart == 0)
		goto A;

B:
	third(path);
	cout << "To restart enter: 0" << endl;
	cin >> restart;
	if (restart == 0)
		goto B;
}
