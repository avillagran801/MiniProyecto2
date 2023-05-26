#pragma once
#include <string>
using namespace std;
// C�digos obtenidos a partir de https://www.geeksforgeeks.org/quad-tree/

struct Point{
    int x;
    int y;
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    Point(){
        x = 0;
        y = 0;
    }
};

struct Data {
    Point pos;
    string city;
    int population; // Como m�nimo. Se pueden guardar otros datos
    Data(Point _pos, string _city, int _population){
        pos = _pos;
        city = _city;
        population = _population;
    }
    Data(){
        population = 0;
    }
};

struct Node {
    // Puntos para marcar el cuadrante
    Point topLeft;
    Point botRight;
    // Estructura que contiene la informaci�n de la ciudad
    Data* data;
    // Punteros a sus hijos
    QuadTree* topLeftNode;
    QuadTree* topRightNode;
    QuadTree* botLeftNode;
    QuadTree* botRightNode;
    Node(Data* _data, Point _topLeft, Point _botRight) {
        data = _data;
        topLeft = _topLeft;
        botRight = _botRight;
        
        topLeftNode = NULL;
        topRightNode = NULL;
        botLeftNode = NULL;
        botRightNode = NULL;
    }
};

class QuadTree{
private:
    int numPoints; // Usados
    int numNodes; // Toooooodos
    Node* root;

public:
    QuadTree();
	int totalPoints(); // Retorna la cantidad de puntos almacenados en el QuadTree
	int totalNodes(); // Retorna la cantidad de nodos, tanto blancos como negros, en el QuadTree
	void insert(Point p, string city, int data); // Inserta un nuevo punto p en el QuadTree, asociando a dicho punto la informaci�n disponible en data(ej.la poblaci�n de una ciudad con coordenadas p).
	void list(); // Retorna un contenedor con todos los puntos almacenados en el QuadTree.Por cada punto retorna sus coordenadas y su valor asociado(ej.la poblaci�n).Para esta funci�n, queda a criterio de los estudiantes elegir un recorrido entre preorder, postorder o una variante de inorder.
	int countRegion(Point p, int distance); //  Retorna la cantidad de puntos en una regi�n del plano, tomando como centro el punto p y una distancia d.
	int aggregateRegion(Point p, int distance); // Retorna la poblaci�n estimada dentro de una regi�n del plano, tomando como centro el punto p y una distancia d.
};