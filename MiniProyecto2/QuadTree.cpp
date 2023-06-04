#include "QuadTree.h"
#include <iostream>
using namespace std;

QuadTree::QuadTree(double _min_width_size) {
	root = new Node(Point(-180, 90), Point(180, -90), _min_width_size); // Definimos los m�rgenes del plano general
	numNodes = 0;
	numPoints = 0;
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

void QuadTree::list() {

}

int QuadTree::countRegion(Point p, int distance) {
	return root->countRegion(p, distance);
}

int QuadTree::aggregateRegion(Point p, int distance) {
	return root->aggregateRegion(p, distance);
}

void QuadTree::printQuadTree() {
	cout << endl << "*** PRINT QUADTREE ***" << endl << endl;
	root->print(root, "", 0);
}