//11. Реализовать   эвристический   алгоритм  решения  задачи
//коммивояжера на основании метода  Прима  нахождения  остовного
//дерева.Проиллюстрировать по шагам этапы поиска(11).
// Граф полный

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

struct PrimeElement {
	int weight;
	int pointerTo;
};

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
	cout << endl;
}
int searchMax(std::string path) {
	ifstream searchMax(path);
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
void generateFullGraph(int points) {
	ofstream out("fullGraph.txt");
	out.clear();
	for (int j = 1; j <= points; j++) {
		for (int i = 1; i <= points; i++) {
			if (j < i) {
				out << j << " " << i << " " << (rand() % 50 + 1);
				if (j == (points - 1) && i == (points)) {
					continue;
				}
				out << endl;
			}			
		}					
	}	
}

int getFinishPoint(vector<vector<int>>* array, int startPoint, int matrixSize) {
	int varWeight = 0;
	for (int i = 1; i < matrixSize; i++) {
		if (i != startPoint) {
			for (int j = 1; j < matrixSize; j++) {
				if (array->at(i)[j] != 0) {
					varWeight++;					
				}
			}
			if (varWeight == 1) {
				return i;
			}
			varWeight = 0;
		}
	}
	return -1;
}

bool isCycleGraph(vector<vector<int>>* array,int matrixSize) {
	int varWeight = 0;
	bool result = true;
	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < matrixSize; j++) {
			if (array->at(i)[j] != 0) {
				varWeight++;
			}			
		}
		if (varWeight == 1) {
			return false;
		}
		varWeight = 0;
	}
	return result;
}

int main() {
	unsigned int graphGenerateStart = clock();
	srand(time(NULL));
	int graphSize = 6;
	//generateFullGraph(graphSize);
	std::cout << "Graph generated! for " << (float)(clock() -graphGenerateStart) / 1000.f << " seconds" << std::endl;
	//std::string path = "fullGraph.txt";
	std::string path = "in.txt";
	int matrixSize = graphSize + 1;
	//int matrixSize = searchMax(path);
	unsigned int programStartTime = clock();
	vector<vector<int>> matrix(matrixSize, vector<int>(matrixSize, INT32_MAX));
	vector<vector<int>> newMatrixPrime(matrixSize, vector<int>(matrixSize, 0));
	ifstream in(path);
	if (in.is_open()) {
		int x = 0, y = 0, weight = 0;
		while (!in.eof()) {  //init array
			in >> x >> y >> weight;
			matrix[x][y] = weight;
			matrix[y][x] = weight;
		}
	}
	std::cout << "Array init! for " << (float)(clock() - graphGenerateStart) / 1000.f << " seconds" << std::endl;
	int startPoint = 1; // вершина откуда начинаем
	int firstPoint = startPoint;
	vector<bool> isVisited(matrixSize, false);  // массив с окончательными метками
	vector<PrimeElement> primeArray(matrixSize, { INT32_MAX, INT32_MAX });  // массив временных меток
	isVisited[0] = true;
	primeArray[0] = {0, 0};
	primeArray[startPoint] = {0 , 0};	
	unsigned int start_time = clock();
	
	int cycle = 0;	
	std::cout << "Prime array init! for " << (float)(clock() - graphGenerateStart) / 1000.f << " seconds" << std::endl;
	std::cout << "Press any key to continue...";
	std::string kek = "0";
	std::cin >> kek;
	while (isfullCheck(&isVisited)) {	
		for (int i = 1; i < matrixSize; i++) {
			if (matrix[startPoint][i] < primeArray[i].weight) { // вес ребра меньше, чем тот, который записан
				primeArray[i] = { matrix[startPoint][i], startPoint };
			}
		}
		//находим самое маленькое ребро
		int finishPoint = 0, weight = INT32_MAX;
		for (int i = 1; i < matrixSize; i++) {
			if (primeArray[i].weight < weight && primeArray[i].weight != 0 && !isVisited[i]) {  // вес ребра самый маленький
				startPoint = primeArray[i].pointerTo;
				finishPoint = i;
				weight = primeArray[i].weight;
			}
		}
		// добавляем новое ребро на граф		
		bool needReplace = false;
		int varFinish = 0, varWeight = INT_FAST32_MAX;
		for (int i = 1; i < matrixSize; i++) {
			if (newMatrixPrime[startPoint][i] != 0 && i != startPoint) {  // ищем самый кототкий
				if (newMatrixPrime[startPoint][i] < varWeight) {
					varWeight = newMatrixPrime[startPoint][i];
					varFinish = i;
					needReplace = true;
				}
			}
		}

		//cout << "Add new graph edge - " << startPoint << " " << finishPoint << " weight = " << matrix[startPoint][finishPoint] << endl;
		newMatrixPrime[startPoint][finishPoint] = matrix[startPoint][finishPoint];
		newMatrixPrime[finishPoint][startPoint] = matrix[startPoint][finishPoint];
		if (needReplace) {
			//cout << "  Delete graph edge - " << startPoint << " " << varFinish << " weight = " << matrix[startPoint][varFinish] << endl;
			//cout << "  Replace graph edge - " << finishPoint << " " << varFinish << " weight = " << matrix[finishPoint][varFinish] << endl;
			newMatrixPrime[startPoint][varFinish] = 0;	// разрываем старую связь
			newMatrixPrime[varFinish][startPoint] = 0;			
			newMatrixPrime[finishPoint][varFinish] = matrix[finishPoint][varFinish]; // создаем новую связь
			newMatrixPrime[varFinish][finishPoint] = matrix[finishPoint][varFinish];
		}		
		isVisited[startPoint] = true;
		isVisited[finishPoint] = true;
		startPoint = finishPoint;
		cout << "\033[2J\033[1;1H";
		cout << cycle << endl;
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
		cycle++;
	}
	// ищем вершину со степенью один для замыкания с началом
	int finishPoint = getFinishPoint(&newMatrixPrime, firstPoint, matrixSize);
	newMatrixPrime[firstPoint][finishPoint] = matrix[firstPoint][finishPoint];
	newMatrixPrime[finishPoint][firstPoint] = matrix[firstPoint][finishPoint];

	unsigned int end_time = clock();
	unsigned int result = end_time - start_time;

	cout << endl << "Algorithm run is " << (float)result / 1000.f << " seconds" << endl;

	//printVector(&matrix);
	//printVector(&newMatrixPrime);

	int graphWeight = 0;
	for (int i = 1; i < newMatrixPrime.size(); i++) {
		for (int j = 1; j < newMatrixPrime.size(); j++) {
			graphWeight += newMatrixPrime[i][j];
		}
	}
	std::cout << endl;
	int iterable = 1, varInt = 1;
	

	vector<bool> exportBoolean(matrixSize, false);
	exportBoolean[1] = true;
	while (iterable < matrixSize ) {
		for (int j = 1; j < matrixSize; j++) {
			if (newMatrixPrime[varInt][j] != 0 && !exportBoolean[j]) {
				std::cout << varInt << "(" << newMatrixPrime[varInt][j] << ")" << j << "->";
				exportBoolean[j] = true;
				varInt = j;
				j = matrixSize;					
			}
		}
		iterable++;
	}
	std::cout << varInt << "(" << newMatrixPrime[varInt][1] << ")" << 1 << std::endl;
	

	std::cout <<endl;
	
	



	cout << endl << "Graph weight  =  " << graphWeight / 2 << endl;

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
	cout << endl;
	if (isCycleGraph(&newMatrixPrime, matrixSize)) {
		cout << "Graph is cycle " << endl;
	}
	else {
		cout << "Error!!! Graph is NOT cycle !!! " << endl;
	}
	
	unsigned int finishTime = clock() - programStartTime;
	cout << endl << "Program run is " << (float)finishTime / 1000.f << " seconds" << endl;
	return 1;
}

// https://graphonline.ru/create_graph_by_edge_list
