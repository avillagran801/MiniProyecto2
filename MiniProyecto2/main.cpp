#include <iostream>
#include <string>
#include "QuadTree.h"
using namespace std;

int main() {
	QuadTree* qt = new QuadTree(90);
	qt->insert(Point(180, -90), "Chiguayante", 15);
	qt->insert(Point(180, 40), "Coronel", 15);
	qt->insert(Point(180, 90), "Concepcion", 15);
	qt->insert(Point(-180, 90), "San Pedro", 15);
	qt->insert(Point(70, 50), "Ciudad fantasma", 30);

	cout << "Total nodes: " << qt->totalNodes() << endl;
	cout << "Total points at a certain distance from (0,0): " << qt->countRegion(Point(0, 0), 1000) << endl;
	cout << "Total population at a certain distance from (0,0): " << qt->aggregateRegion(Point(0, 0), 1000) << endl;

	qt->printQuadTree();
	
	cout << "Cities Summary" << endl;
	vector<Data> Cities = qt->list();

	for (int i = 0; i < Cities.size(); ++i){
		cout << "///City: " << Cities[i].city << " ///Population: " << Cities[i].population << " ///Coordinates: " << Cities[i].position.x << " , " << Cities[i].position.y << endl;
	}


	return 0;
}