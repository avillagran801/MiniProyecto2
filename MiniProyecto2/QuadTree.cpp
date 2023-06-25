#include "QuadTree.h"
#include <iostream>
using namespace std;

QuadTree::QuadTree(double _min_width_size) {
	root = new Node(Point(-180, 90), Point(180, -90), _min_width_size); // Definimos los márgenes del plano general
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
	// Relegamos la inserción a root. Si es válida la inserción, numPoints aumenta en 1
	if (root->insert(p, city, population)) {
		numPoints++;
	}
}

vector<Data> QuadTree::list() {
	return root->list();
}

long long QuadTree::countRegion(Point p, int distance) {
	Point _topLeft = Point(p.longitude - distance*MIN_WIDTH_SIZE, p.latitude + distance*MIN_WIDTH_SIZE/2);
	Point _botRight = Point(p.longitude + distance*MIN_WIDTH_SIZE, p.latitude - distance*MIN_WIDTH_SIZE/2);

	return root->countRegion(_topLeft, _botRight);
}

long long QuadTree::aggregateRegion(Point p, int distance) {
	Point _topLeft = Point(p.longitude - distance * MIN_WIDTH_SIZE, p.latitude + distance * MIN_WIDTH_SIZE / 2);
	Point _botRight = Point(p.longitude + distance * MIN_WIDTH_SIZE, p.latitude - distance * MIN_WIDTH_SIZE / 2);

	return root->aggregateRegion(_topLeft, _botRight);
}

void QuadTree::printQuadTree() {
	cout << endl << "*** PRINT QUADTREE ***" << endl << endl;
	root->print(root, "", 0);
}
