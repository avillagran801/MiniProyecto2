#pragma once
#include <string>
#include <vector>
#include <cmath>
using namespace std;
// Códigos obtenidos a partir de https://www.geeksforgeeks.org/quad-tree/

// ES NECESARIO ESTABLECER UNA MEDIDA MÍNIMA PARA DEJAR DE DIVIDIR LOS CUADRADOS

struct Point { // Se trabaja con ángulos
    double longitude;
    double latitude;
    Point(double _x, double _y) {
        longitude = _x;
        latitude = _y;
    }
    Point() {
        longitude = 0;
        latitude = 0;
    }
};

struct Data {
    Point position;
    string city;
    int population;
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
    double MIN_WIDTH_SIZE;
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
    bool isLeaf();
    int countRegion(Point _topLeftP, Point _botRightP);
    int aggregateRegion(Point _topLeftP, Point _botRightP);
    vector<Data> list();
    void print(Node* node, string indent, int branch);
};

