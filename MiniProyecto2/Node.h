#pragma once
#include <string>
#include <cmath>
using namespace std;
// C�digos obtenidos a partir de https://www.geeksforgeeks.org/quad-tree/

// ES NECESARIO ESTABLECER UNA MEDIDA M�NIMA PARA DEJAR DE DIVIDIR LOS CUADRADOS
const double MIN_SQUARE_SIZE = 10;

struct Point { // Se trabaja con �ngulos
    double x;
    double y;
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    Point() {
        x = 0;
        y = 0;
    }
};

struct Data {
    Point position;
    string city;
    int population; // Como m�nimo. Se pueden guardar otros datos
    Data(Point _position, string _city, int _population) {
        position = _position;
        city = _city;
        population = _population;
    }
    Data() {
        population = 0;
    }
};

class Node{
private:
    // Puntos para marcar el cuadrante
    Point topLeft;
    Point botRight;
    // Estructura que contiene la informaci�n de la ciudad. De llegar al nivel m�s bajo, se agregan los datos como arreglo
    Data* data;
    // Punteros a sus hijos
    Node* topLeftNode;
    Node* topRightNode;
    Node* botLeftNode;
    Node* botRightNode;

public:
    Node(Point _topLeft, Point _botRight); // Constructor s�lo con puntos
    Node(Data* _data, Point _topLeft, Point _botRight); // Constructor con puntos y datos
    void insert(Point _p, string _city, int _population);
    bool inBoundary(Point evaluate);
};

