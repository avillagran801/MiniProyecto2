#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(Point _topLeft, Point _botRight, double _min_width_size) {
    topLeft = _topLeft;
    botRight = _botRight;
    topLeftNode = NULL;
    topRightNode = NULL;
    botLeftNode = NULL;
    botRightNode = NULL;
    MIN_WIDTH_SIZE = _min_width_size;
}

bool Node::insert(Point _p, string _city, int _population) {
    // Si el punto no está dentro de los límites del nodo, return
    if (inBoundary(_p) == false) {
        //cout << "IN BOUNDARY FALSE" << endl << endl;
        return false;
    }

    // Si alcanzamos el tamaño mínimo de área, agregamos el valor a data
    if (botRight.x - topLeft.x <= MIN_WIDTH_SIZE){
        //cout << "LLEGAMOS AL ULTIMO NIVEL!" << endl << endl;
        data.push_back(Data(_p, _city, _population));
        return true;
    }

    // Si aún es posible dividir los cuadrados, inicia la recursión hasta alcanzar el tamaño mínimo de área

    //cout << "*** CURRENT BOUNDS ***" << endl;
    //cout << "TopLeft: " << topLeft.x << ", " << topLeft.y << endl;
    //cout << "BotRight: " << botRight.x << ", " << botRight.y << endl;

    // Izquierda del plano
    if ((botRight.x - topLeft.x)/2 + topLeft.x >= _p.x) {
        // Bottom left
        if ((topLeft.y - botRight.y)/2 + botRight.y >= _p.y){
            //cout << "BOTTOM LEFT" << endl << endl;
            // Si no existe, lo creamos
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.x, topLeft.y - (topLeft.y - botRight.y) / 2), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y)), MIN_WIDTH_SIZE);
            }
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.x, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), MIN_WIDTH_SIZE);
            }
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), Point(botRight.x, botRight.y), MIN_WIDTH_SIZE);
            }
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x), topLeft.y - (topLeft.y - botRight.y) / 2), MIN_WIDTH_SIZE);
            }
            botLeftNode->insert(_p, _city, _population);
        }
        // Top left
        else {
            //cout << "TOP LEFT" << endl << endl;
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.x, topLeft.y - (topLeft.y - botRight.y) / 2), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y)), MIN_WIDTH_SIZE);
            }
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.x, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), MIN_WIDTH_SIZE);
            }
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), Point(botRight.x, botRight.y), MIN_WIDTH_SIZE);
            }
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x), topLeft.y - (topLeft.y - botRight.y) / 2), MIN_WIDTH_SIZE);
            }
            topLeftNode->insert(_p, _city, _population);
        }
    }
    // Derecha del plano
    else {
        // Bottom right
        if ((topLeft.y - botRight.y) / 2 + botRight.y >= _p.y) {
            //cout << "BOTTOM RIGHT" << endl << endl;
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.x, topLeft.y - (topLeft.y - botRight.y) / 2), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y)), MIN_WIDTH_SIZE);
            }
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.x, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), MIN_WIDTH_SIZE);
            }
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), Point(botRight.x, botRight.y), MIN_WIDTH_SIZE);
            }
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x), topLeft.y - (topLeft.y - botRight.y) / 2), MIN_WIDTH_SIZE);
            }
            botRightNode->insert(_p, _city, _population);
        }
        // Top right
        else {
            //cout << "TOP RIGHT" << endl << endl;
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.x, topLeft.y - (topLeft.y - botRight.y) / 2), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y)), MIN_WIDTH_SIZE);
            }
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.x, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), MIN_WIDTH_SIZE);
            }
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y - (topLeft.y - botRight.y) / 2), Point(botRight.x, botRight.y), MIN_WIDTH_SIZE);
            }
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.x + (botRight.x - topLeft.x) / 2, topLeft.y), Point(topLeft.x + (botRight.x - topLeft.x), topLeft.y - (topLeft.y - botRight.y) / 2), MIN_WIDTH_SIZE);
            }
            topRightNode->insert(_p, _city, _population);
        }
    }
}

bool Node::inBoundary(Point evaluate) { // Esto en base a nuestro plano de referencia, donde el 0 es el punto de al medio
    return (evaluate.x >= topLeft.x && evaluate.x <= botRight.x && evaluate.y <= topLeft.y && evaluate.y >= botRight.y);
}

int Node::getNumNodes() {
    int nodes = 0;
    if (topLeftNode != NULL) {
        nodes = nodes + topLeftNode->getNumNodes();
    }
    if (topRightNode != NULL) {
        nodes = nodes + topRightNode->getNumNodes();
    }
    if (botLeftNode != NULL) {
        nodes = nodes + botLeftNode->getNumNodes();
    }
    if (botRightNode != NULL) {
        nodes = nodes + botRightNode->getNumNodes();
    }

    if (nodes == 0) return 1;
    else return nodes + 1;
}