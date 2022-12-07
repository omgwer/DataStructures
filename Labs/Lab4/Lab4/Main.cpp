//11. Реализовать   эвристический   алгоритм  решения  задачи
//коммивояжера на основании метода  Прима  нахождения  остовного
//дерева.Проиллюстрировать по шагам этапы поиска(11).

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
			if (matrix[i][j] == INT32_MAX)
				cout << " 0 ";
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
	vector<vector<int>> matrix(searchMax(), vector<int>(searchMax(), INT32_MAX));
	vector<vector<int>> newMatrixPrime(searchMax(), vector<int>(searchMax(), 0));
	vector<bool> isVisited(searchMax(), false);
	int matrixSize = matrix.size();
	isVisited[0] = true;
	ifstream in("in.txt");
	if (in.is_open()) {
		int x = 0, y = 0, weight = 0;
		while (!in.eof()) {  //init array
			in >> x >> y >> weight;
			matrix[x][y] = weight;
			matrix[y][x] = weight;
		}
	}
	int startPointX = 0;
	int startPointY = 0;
	int iterableWeight = INT32_MAX;
	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < matrixSize; j++) {
			if (matrix[i][j] < iterableWeight) {
				iterableWeight = matrix[i][j];
				startPointX = i;
				startPointY = j;
			}
		}
	}
	newMatrixPrime[startPointX][startPointY] = iterableWeight;
	newMatrixPrime[startPointY][startPointX] = iterableWeight;
	vector<bool> testVector(matrix.size(), false);
	testVector[0] = true;
	testVector[startPointX] = true;
	testVector[startPointY] = true;
	
	while (isfullCheck(&testVector)) { // ищем остов
		startPointX = 0;
		startPointY = 0;
		iterableWeight = INT32_MAX;
		for (int i = 1; i < matrixSize; i++) {
			if (testVector[i]) {	// если входят анализируемые вершины графа
				for (int j = 1; j < matrixSize; j++) {
					if (!testVector[j]) { // если 2 вершины графа входят в остовной граф, их нет смысла рассматривать
						if (matrix[i][j] < iterableWeight) {
							iterableWeight = matrix[i][j];
							startPointX = i;
							startPointY = j;
						}
					}										
				}
			}
		}
		int newMatrixInputX = 0;
		int newMatrixInputY = 0;
		int newMatrixWeight = INT32_MAX;
		bool needReplace = false;
		for (int i = 1; i < matrixSize; i++) { // нужно поискать, есть ли возможность срезать угол
			if (matrix[startPointY][i] != INT32_MAX && matrix[startPointX][i] != INT32_MAX) { // значит они указывают в одно место
				if (matrix[startPointX][i] < newMatrixWeight) {
					needReplace = true;
					newMatrixWeight = matrix[startPointX][i];
					newMatrixInputX = startPointX;
					newMatrixInputY = i;
				}
			}
		} 

		if (needReplace) {  // если графы необходимо перепривязать
			newMatrixPrime[newMatrixInputX][newMatrixInputY] = INT32_MAX; // удаляем старую привязку
			newMatrixPrime[newMatrixInputY][newMatrixInputX] = INT32_MAX;

			newMatrixPrime[newMatrixInputY][startPointY] = newMatrixWeight;  // делаем связь отвязанной вершины с новой вершиной
			newMatrixPrime[startPointY][newMatrixInputY] = newMatrixWeight;

			newMatrixPrime[startPointX][startPointY] = iterableWeight;  //добавляем новую вершину
			newMatrixPrime[startPointY][startPointX] = iterableWeight;
			testVector[startPointY] = true;
		}
		else {  // если не надо
			newMatrixPrime[startPointX][startPointY] = iterableWeight;
			newMatrixPrime[startPointY][startPointX] = iterableWeight;
			testVector[startPointY] = true;
		}		
	}

	printVector(&matrix);
	cout << endl;
	printVector(&newMatrixPrime);

	int graphWeight = 0;
	for (int i = 1; i < newMatrixPrime.size(); i++) {
		for (int j = 1; j < newMatrixPrime.size(); j++) {
			graphWeight += newMatrixPrime[i][j];
		}
	}
	cout << endl << graphWeight / 2 << endl;
	

	
	return 1;
}