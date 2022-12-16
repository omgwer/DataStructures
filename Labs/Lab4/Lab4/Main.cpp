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
int getPointWeight(vector<int>* test) {
	int result = 0;
	for (int i = 1; i < test->size(); i++) {
		int test1 = test->at(i);
		if (test1 != 0)
			result++;		
	}
	return result;
}
bool isPointOverload(vector<int>* test) {  // это значит, что у данной вершины уже есть два ребра
	int result = 0;
	for (int i = 1; i < test->size(); i++) {
		int test1 = test->at(i);
		if (test1 != 0)
			result++;
		if (result >= 2)
			return true;		
	}	
	return false;
}
bool isTriangle() {  // проверка получится ли треугольник, если добавить еще одно ребро.
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
	newMatrixPrime[startPointX][startPointY] = iterableWeight;  // нашли минимальное ребро
	newMatrixPrime[startPointY][startPointX] = iterableWeight;
	vector<bool> testVector(matrix.size(), false);
	testVector[0] = true;
	testVector[startPointX] = true;
	testVector[startPointY] = true;
	int lastPositionX =0;
	int lastPositionY =0;
	
	while (isfullCheck(&testVector)) {
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
		newMatrixPrime[startPointX][startPointY] = iterableWeight;
		newMatrixPrime[startPointY][startPointX] = iterableWeight;
		testVector[startPointY] = true;	
		lastPositionX = startPointX;
		lastPositionY = startPointY;
	}
	bool isClosed = false;
	
	while (!isClosed) {  // ищем две любые незамкнутые вершины, между которыми минимальное расстояние, если вершина одна, то вклиниваем ее куда нибудь.
		isClosed = true;
		int firstPoint = 0;
		int secondPoint = 0;
		int varWeight = INT32_MAX;
		for (int i = 1; i < matrixSize; i++) {  // нужно замкнуть граф
			for (int j = 1; j < matrixSize; j++) {
				if (getPointWeight(&newMatrixPrime[i]) < 2 && getPointWeight(&newMatrixPrime[j]) < 2) { // есть две вершины, у которых меньше двух ребер
					if (matrix[i][j] < varWeight ) {  // между ребрами есть связь и эта комбинация меньше, чем запомненная
						isClosed = false;
						firstPoint = i;
						secondPoint = j;
						varWeight = matrix[i][j];
					}
				}
			}
		}
		if (firstPoint != 0) {  // значит нашлись две вершины, которые можно соединить
			newMatrixPrime[firstPoint][secondPoint] = varWeight;
			newMatrixPrime[secondPoint][firstPoint] = varWeight;
		}
		else {  // такая вершина одна. нужно ее подсунуть ближайшей вершине, чтобы вес минимально вырос
			int replacementPoint = 0;
			for (int i = 1; i < matrixSize; i++) {  // нужно замкнуть граф
				if (getPointWeight(&newMatrixPrime[i]) < 2 ) { // нашлась хоть одна одинокая вершина  // тут не проверяется, есть лу у вершины вообще больше двух reber					
					replacementPoint = i;
					isClosed = false;
					for (int j = 1; j < matrixSize; j++) {  // нужно найти треугольник наименьшего веса
						for (int k = 1; k < matrixSize; k++) {
							if (matrix[i][j] != INT32_MAX && matrix[i][k] != INT32_MAX && matrix[k][j] != INT32_MAX) {  // из одинокой вершины есть две вершины, связанные между собой 
								int varRes = matrix[i][j] + matrix[i][k];   // сумма двух ребер, которые хотим добавить
								if (varRes < varWeight ) {  // ищем минимальную сумму ребер
									varWeight = varRes; 
									firstPoint = k;
									secondPoint = j;
								}								
							}
						}
					}
					i = matrixSize;					
				}
			}
			// нужно обновить связи в ребрах  ( если обрывается связь ставим 0)
			newMatrixPrime[firstPoint][secondPoint] = 0;  // разрываем старую связь
			newMatrixPrime[secondPoint][firstPoint] = 0;
			newMatrixPrime[replacementPoint][firstPoint] = matrix[replacementPoint][firstPoint];  // добавляем первое ребро
			newMatrixPrime[firstPoint][replacementPoint] = matrix[replacementPoint][firstPoint];
			newMatrixPrime[replacementPoint][secondPoint] = matrix[replacementPoint][secondPoint];  // добавляем второе ребро
			newMatrixPrime[secondPoint][replacementPoint] = matrix[replacementPoint][secondPoint];
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

	ofstream out("out.txt");
	vector<bool> exportBool(matrixSize, false);
	out.clear();
	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < matrixSize; j++) {
			if (newMatrixPrime[i][j] != 0) {
				out << i << "-(" << newMatrixPrime[i][j] << ")-" << j << endl;
			}
		}
	}
		
	return 1;
}

// https://graphonline.ru/create_graph_by_edge_list
