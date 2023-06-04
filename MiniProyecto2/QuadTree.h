#pragma once
#include <string>
#include <vector>
#include "Node.h"
using namespace std;

class QuadTree{
private:
    int numPoints; // Usados
    int numNodes; // Toooooodos
    Node* root;

public:
    QuadTree(double _min_square_size);
	int totalPoints(); // Retorna la cantidad de puntos almacenados en el QuadTree
	int totalNodes(); // Retorna la cantidad de nodos, tanto blancos como negros, en el QuadTree
	void insert(Point p, string city, int population); // Inserta un nuevo punto p en el QuadTree, asociando a dicho punto la información disponible en data(ej.la población de una ciudad con coordenadas p).
	void list(); // Retorna un contenedor con todos los puntos almacenados en el QuadTree.Por cada punto retorna sus coordenadas y su valor asociado(ej.la población).Para esta función, queda a criterio de los estudiantes elegir un recorrido entre preorder, postorder o una variante de inorder.
	int countRegion(Point p, int distance); //  Retorna la cantidad de puntos en una región del plano, tomando como centro el punto p y una distancia d.
	int aggregateRegion(Point p, int distance); // Retorna la población estimada dentro de una región del plano, tomando como centro el punto p y una distancia d.
	void printQuadTree();
};