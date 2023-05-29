#include <iostream>
#include <string>
#include "QuadTree.h"
using namespace std;

int main() {
	QuadTree* qt = new QuadTree();
	qt->insert(Point(180, -90), "Conce", 15);


	return 0;
}