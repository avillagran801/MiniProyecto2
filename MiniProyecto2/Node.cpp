#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(Point _topLeft, Point _botRight) {
    topLeft = _topLeft;
    botRight = _botRight;
    data = NULL;
    topLeftNode = NULL;
    topRightNode = NULL;
    botLeftNode = NULL;
    botRightNode = NULL;
}

Node::Node(Data* _data, Point _topLeft, Point _botRight) {
    data = _data;
    topLeft = _topLeft;
    botRight = _botRight;

    topLeftNode = NULL;
    topRightNode = NULL;
    botLeftNode = NULL;
    botRightNode = NULL;
}

// DECIDIR QUÉ HACER SI 2 PUNTOS CAEN EN EL MISMO LUGAR
void Node::insert(Point _p, string _city, int _data) {
    // Si el punto no está dentro de los límites del nodo, return
    
    /*
    if (inBoundary(_p) == false) {
        cout << "IN BOUNDARY FALSE" << endl;
        return;
    }
    */

    // Si alcanzamos el tamaño mínimo de área
    if (abs(topLeft.y - botRight.y) <= MIN_SQUARE_SIZE && abs(botRight.x - topLeft.x) <= MIN_SQUARE_SIZE){
        // Decidir qué hacer con la ciudad a agregar y finaliza con return
        cout << "LLEGAMOS AL ULTIMO NIVEL!" << endl;
        return;
    }

    // Si aún es posible dividir los cuadrados, inicia la recursión hasta alcanzar el tamaño mínimo de área

    cout << "*** CURRENT BOUNDS ***" << endl;
    cout << "TopLeft: " << topLeft.x << ", " << topLeft.y << endl;
    cout << "BotRight: " << botRight.x << ", " << botRight.y << endl;

    // Izquierda del plano
    if ((botRight.x - topLeft.x)/2 + topLeft.x >= _p.x) {
        // Bottom left
        if ((topLeft.y - botRight.y)/2 + botRight.y >= _p.y){
            cout << "BOTTOM LEFT" << endl;
            // Si no existe, lo creamos
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.x, topLeft.y - (topLeft.y - botRight.y) / 2), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2));
            }
            botLeftNode->insert(_p, _city, _data);
        }
        // Top left
        else {
            cout << "TOP LEFT" << endl;
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.x, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2));
            }
            topLeftNode->insert(_p, _city, _data);
        }
    }
    // Derecha del plano
    else {
        // Bottom right
        if ((topLeft.y - botRight.y) / 2 + botRight.y >= _p.y) {
            cout << "BOTTOM RIGHT" << endl;
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), Point(botRight.x, botRight.y));
            }
            botRightNode->insert(_p, _city, _data);
        }
        // Top right
        else {
            cout << "TOP RIGHT" << endl;
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2));
            }
            topRightNode->insert(_p, _city, _data);
        }

    }
}

bool Node::inBoundary(Point evaluate) { // Esto en base a nuestro plano de referencia, donde el 0 es el punto de al medio
    return (evaluate.x >= topLeft.x && evaluate.x <= botRight.x && evaluate.y <= topLeft.y && evaluate.y >= botRight.y);
}