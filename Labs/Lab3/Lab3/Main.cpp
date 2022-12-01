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
	return result;
}


int main() {	
	vector<vector<int>> matrix(searchMax(), vector<int>(searchMax(), 0));
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
	
		
	return 1;
}
