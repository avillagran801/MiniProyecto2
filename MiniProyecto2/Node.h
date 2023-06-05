#pragma once
#include <string>
#include <vector>
#include <cmath>
using namespace std;
// Códigos obtenidos a partir de https://www.geeksforgeeks.org/quad-tree/

// ES NECESARIO ESTABLECER UNA MEDIDA MÍNIMA PARA DEJAR DE DIVIDIR LOS CUADRADOS

struct Point { // Se trabaja con ángulos
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
    double population; // Como mínimo. Se pueden guardar otros datos
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
    int MIN_WIDTH_SIZE;
    // Puntos para marcar el cuadrante
    Point topLeft;
    Point botRight;
    // Estructura que contiene la información de la ciudad. De llegar al nivel más bajo, se agregan los datos como arreglo
    vector<Data> data;
    // Punteros a sus hijos
    Node* topLeftNode;
    Node* topRightNode;
    Node* botLeftNode;
    Node* botRightNode;

public:
    Node(Point _topLeft, Point _botRight, double _min_width_size); // Constructor para el nodo raíz, le entregamos el ancho mínimo
    bool insert(Point _p, string _city, int _population);
    bool inBoundary(Point evaluate);
    int getNumNodes();
    int countRegion(Point p, int distance);
    int aggregateRegion(Point p, int distance);
    bool isLeaf();
    void print(Node* node, string indent, int branch);
    vector<Data> list();
};

