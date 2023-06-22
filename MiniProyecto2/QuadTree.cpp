#include "QuadTree.h"
#include <iostream>
using namespace std;

QuadTree::QuadTree(double _min_width_size) {
	root = new Node(Point(-180, 90), Point(180, -90), _min_width_size); // Definimos los m�rgenes del plano general
	numNodes = 0;
	numPoints = 0;
    MIN_WIDTH_SIZE = _min_width_size;
}

int QuadTree::totalPoints() {
	return numPoints;
}

int QuadTree::totalNodes() {
	return root->getNumNodes();
}

void QuadTree::insert(Point p, string city, int population) {
	// Relegamos la inserci�n a root. Si es v�lida la inserci�n, numPoints aumenta en 1
	if (root->insert(p, city, population)) {
		numPoints++;
	}
}

vector<Data> QuadTree::list() {
	return root->list();
}

int QuadTree::countRegion(Point p, int distance) {
	Point _topLeft = Point(p.longitude - distance*MIN_WIDTH_SIZE, p.latitude + distance*MIN_WIDTH_SIZE/2);
	Point _botRight = Point(p.longitude + distance*MIN_WIDTH_SIZE, p.latitude - distance*MIN_WIDTH_SIZE/2);

	return root->countRegion(_topLeft, _botRight);
}

int QuadTree::aggregateRegion(Point p, int distance) {
	Point _topLeft = Point(p.longitude - distance * MIN_WIDTH_SIZE, p.latitude + distance * MIN_WIDTH_SIZE / 2);
	Point _botRight = Point(p.longitude + distance * MIN_WIDTH_SIZE, p.latitude - distance * MIN_WIDTH_SIZE / 2);

	return root->aggregateRegion(_topLeft, _botRight);
}

void QuadTree::printQuadTree() {
	cout << endl << "*** PRINT QUADTREE ***" << endl << endl;
	root->print(root, "", 0);
}