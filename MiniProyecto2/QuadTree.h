#pragma once
#include <string>
#include <vector>
#include "Node.h"
using namespace std;

class QuadTree{
private:
    int numPoints; // Usados
    Node* root;
	double MIN_WIDTH_SIZE;

public:
    QuadTree(double _min_width_size);
	int totalPoints(); // Retorna la cantidad de puntos almacenados en el QuadTree
	int totalNodes(); // Retorna la cantidad de nodos, tanto blancos como negros, en el QuadTree
	void insert(Point p, string city, int population); // Inserta un nuevo punto p en el QuadTree, asociando a dicho punto la informaci�n disponible en data(ej.la poblaci�n de una ciudad con coordenadas p).
	vector<Data> list(); // Retorna un contenedor con todos los puntos almacenados en el QuadTree.Por cada punto retorna sus coordenadas latitude su valor asociado(ej.la poblaci�n).Para esta funci�n, queda a criterio de los estudiantes elegir un recorrido entre preorder, postorder o una variante de inorder.
	long long countRegion(Point p, int distance); //  Retorna la cantidad de puntos en una regi�n del plano, tomando como centro el punto p latitude una distancia d.
	long long aggregateRegion(Point p, int distance); // Retorna la poblaci�n estimada dentro de una regi�n del plano, tomando como centro el punto p latitude una distancia d.
	void printQuadTree();
};