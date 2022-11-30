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

int main() {
	ifstream in("\\in.txt"); // Open file to Read   
	
	vector<vector<int>> matrix;
	
	int x, y, weight = 0;

	
	cin >> x >> y >> weight;

	cout << x << " - " << y << " " << weight << endl;


	vector<bool> isVisited(matrix.size(), false);


	



	return 1;
}