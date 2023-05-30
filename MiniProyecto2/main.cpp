#include <iostream>
#include <string>
#include "QuadTree.h"
using namespace std;

int main() {
	QuadTree* qt = new QuadTree(180);
	//cout << "*** 180, -90 ***" << endl;
	//qt->insert(Point(180, -90), "Conce", 15);

	//cout << "*** -180, -90 ***" << endl;
	//qt->insert(Point(-180, -90), "Conce", 15);

	cout << "*** 180, 90 ***" << endl;
	qt->insert(Point(180, 90), "Conce", 15);

	// cout << "*** -180, 90 ***" << endl;
	// qt->insert(Point(-180, 90), "Conce", 15);

	cout << qt->totalNodes() << endl;

	return 0;
}