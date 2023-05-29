#include "QuadTree.h"
using namespace std;

QuadTree::QuadTree() {
	root = new Node(Point(-180, 90), Point(180, -90)); // Definimos los márgenes del plano general
	numNodes = 0;
	numPoints = 0;
}

int QuadTree::totalPoints() {
	return numPoints;
}

int QuadTree::totalNodes() {
	return numNodes;
}

void QuadTree::insert(Point p, string city, int population) {
	// Relegamos la inserción a root
	root->insert(p, city, population);
}

void QuadTree::list() {

}

int QuadTree::countRegion(Point p, int distance) {
	return 1; // CAMBIAR, ES PARA QUE COMPILE
}

int QuadTree::aggregateRegion(Point p, int distance) {
	return 1; // CAMBIAR, ES PARA QUE COMPILE
}