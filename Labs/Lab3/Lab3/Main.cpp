//19. »меетс€  сеть  автомобильных  дорог.ƒл€ каждой дороги
//известна максимальна€ масса груза, которую можно  провезти  по
//этой   дороге.—   помощью  алгоритма  ƒейкстры   определить
//максимальный   груз, который  можно  провести  между   двум€
//указанными городам(10).

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Main.h"

using namespace std;
using std::cout;
using std::cin;

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
	vector<vector<int>> matrix(searchMax(), vector<int>(searchMax(), -1));
	vector<bool> isVisited(searchMax(), false);
	int startPoint, finishPoint;
	ifstream in("in.txt");
	if (in.is_open()) {
		int x = 0, y = 0, weight = 0;
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
	vector<int> result(matrixSize, -1);
	result[startPoint] = INT32_MAX;
	result[0] = 0;
	bool error = true;

	while (isfullCheck(&isVisited) && error) {
		error = false;
		for (int i = 1; i < matrixSize; i++) {
			if (!isVisited[i] && matrix[currentPoint][i] > 0) {  //ѕройденные вершины не смотрим
				int first = min(result[currentPoint], matrix[currentPoint][i]);  // это минимальное значение ребра целиком
				int test = max(first, result[i]);
				result[i] = test;
				error = true;
			}		
		}
		isVisited[currentPoint] = true;
		// search new currentPoint
		int varCurrentPoint = 0;
		int varWeight = 0;
		for (int i = 1; i < matrixSize; i++) {
			if ( !isVisited[i] && result[i] > varWeight) {
				varCurrentPoint = i;	
				varWeight = result[i];
			}				
		}
		currentPoint = varCurrentPoint;
	}
	
	if (result[finishPoint] < 0) {
		cout << "Error!!! Graph point not linked!!!" << endl;
	}
	else {
		for (int i = 1; i < matrixSize; i++) {
			if (result[i] == INT32_MAX)
				cout << "* ";
			else
				cout << result[i] << " ";
		}
		cout << endl;
		cout << "The weight between " << startPoint << " and " << finishPoint << " = " << result[finishPoint] << endl;
	}	
	
	return 1;
}