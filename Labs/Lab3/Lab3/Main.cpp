//19. Имеется  сеть  автомобильных  дорог.Для каждой дороги
//известна максимальная масса груза, которую можно  провезти  по
//этой   дороге.С   помощью  алгоритма  Дейкстры   определить
//максимальный   груз, который  можно  провести  между   двумя
//указанными городам(10).

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<vector<int>>* test) {
	vector<vector<int>> matrix = *test;

	for (int i = 1;i < matrix.size(); i++) {
		cout << " ";
		for (int j = 1; j < matrix.size(); j++) {	
			if (matrix[i][j] == INT16_MAX)
				cout << " - ";
			else
			{
				int test = matrix[i][j];
				if ((test - 10) < 0) {
					cout << " " << test << " ";
				}
				else if ((test - 100) < 0) {
					cout << " " << test;
				}
			}
		}
		cout << endl;
	}
}

void printReturnPath(int start, int finish, vector<vector<int>>* test) {
	vector<vector<int>> matrix = *test;
	vector<int> result;
	int finishWeight = matrix[start][finish]; // конечный вес
	int varPoint = finish;
	matrix[start][start] = 0;
	result.push_back(finish);
	while (start != varPoint) {
		for (int i = matrix.size() - 1; i >= 1; i--) {
			if (matrix[varPoint][i] != INT16_MAX) {
				int temp = finishWeight - matrix[varPoint][i];
				if (matrix[i][start] == temp) {
					finishWeight = temp;
					varPoint = i;
					result.push_back(i);
				}
			}
		}
	}
	cout << "Direct for finist point : ";
	
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i];
		if (i != 0) {
			cout << " -> ";
		}
	}

	cout << endl;
}

int searchMax() {
	ifstream searchMax("in.txt");
	int result = 0, max = 0;
	if (searchMax.is_open()) {
		while (!searchMax.eof()) {  
			searchMax >> max;
			if (max > result) {
				result = max;
			}
			searchMax >> max;
			if (max > result) {
				result = max;
			}
			searchMax >> max;
		}
	}
	searchMax.close();
	return result + 1;
}

bool isfullCheck(vector<bool>* isVisited) {
	for (int i = 1; i < isVisited->size(); i++)
	{
		if (isVisited->at(i) == false) {
			return true;
		}
	}
	return false;
}


int main() {
	vector<vector<int>> matrix(searchMax(), vector<int>(searchMax(), INT16_MAX));
	vector<bool> isVisited(searchMax(), false);
	int x = 0, y = 0, weight = 0, startPoint, finishPoint;
	ifstream in("in.txt");
	if (in.is_open()) {
		while (!in.eof()) {  //init array
			in >> x >> y >> weight;
			matrix[x][y] = weight;
			matrix[y][x] = weight;
		}
	}
	cout << "Input start Point - ";
	cin >> startPoint;
	cout << endl;
	cout << "Input finish Point - ";
	cin >> finishPoint;
	cout << endl;
	isVisited[0] = true;
	isVisited[startPoint] = true;	
	int currentPoint = startPoint;
	int matrixSize = matrix.size();

	while (isfullCheck(&isVisited)) {
		int varInt = INT16_MAX;
		int varCurrentPoint = currentPoint;
		for (int i = 1; i < matrixSize; i++) { //пробегаемся и ищем следующий элемент
			if (matrix[currentPoint][i] < varInt && isVisited[i] == false) { // новый элемент должен быть меньше всех и не быть пройденным
				varInt = matrix[currentPoint][i];
				varCurrentPoint = i;
			}
		}
		currentPoint = varCurrentPoint;
		isVisited[currentPoint] = true;
		for (int i = 1; i < matrixSize; i++) { // обходим все соседние элементы и пересчитываем коэффициенты			
			int test1 = matrix[startPoint][i] + matrix[currentPoint][i];
			int test2 = matrix[currentPoint][startPoint];
			if (test1 < test2) {  //пытаемся уменьшить расстояние 
				matrix[startPoint][currentPoint] = matrix[startPoint][i] + matrix[currentPoint][i];
				matrix[currentPoint][startPoint] = matrix[startPoint][i] + matrix[currentPoint][i];
			}
		}
	}
	cout << "The distance between " << startPoint << " and " << finishPoint << " = " << matrix[startPoint][finishPoint] << endl;
	cout << endl;
	printVector(&matrix);
	cout << endl;
	printReturnPath(startPoint, finishPoint, &matrix);
	return 1;
}