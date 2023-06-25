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
        return false;
    }

    // Si alcanzamos el tamaño mínimo de área, agregamos el valor a data
    if (botRight.longitude - topLeft.longitude <= MIN_WIDTH_SIZE){
        data.push_back(Data(_p, _city, _population));
        return true;
    }

    // Si aún es posible dividir los cuadrados, inicia la recursión hasta alcanzar el tamaño mínimo de área

    // Izquierda del plano
    if ((botRight.longitude - topLeft.longitude)/2 + topLeft.longitude >= _p.longitude) {
        // Bottom left
        if ((topLeft.latitude - botRight.latitude)/2 + botRight.latitude >= _p.latitude){
            // Si no existe, lo creamos
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.longitude, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude)), MIN_WIDTH_SIZE);
            }
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.longitude, topLeft.latitude), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), MIN_WIDTH_SIZE);
            }
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), Point(botRight.longitude, botRight.latitude), MIN_WIDTH_SIZE);
            }
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude), topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), MIN_WIDTH_SIZE);
            }
            botLeftNode->insert(_p, _city, _population);
        }
        // Top left
        else {
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.longitude, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude)), MIN_WIDTH_SIZE);
            }
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.longitude, topLeft.latitude), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), MIN_WIDTH_SIZE);
            }
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), Point(botRight.longitude, botRight.latitude), MIN_WIDTH_SIZE);
            }
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude), topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), MIN_WIDTH_SIZE);
            }
            topLeftNode->insert(_p, _city, _population);
        }
    }
    // Derecha del plano
    else {
        // Bottom right
        if ((topLeft.latitude - botRight.latitude) / 2 + botRight.latitude >= _p.latitude) {
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.longitude, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude)), MIN_WIDTH_SIZE);
            }
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.longitude, topLeft.latitude), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), MIN_WIDTH_SIZE);
            }
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), Point(botRight.longitude, botRight.latitude), MIN_WIDTH_SIZE);
            }
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude), topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), MIN_WIDTH_SIZE);
            }
            botRightNode->insert(_p, _city, _population);
        }
        // Top right
        else {
            if (botLeftNode == NULL) {
                botLeftNode = new Node(Point(topLeft.longitude, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude)), MIN_WIDTH_SIZE);
            }
            if (topLeftNode == NULL) {
                topLeftNode = new Node(Point(topLeft.longitude, topLeft.latitude), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), MIN_WIDTH_SIZE);
            }
            if (botRightNode == NULL) {
                botRightNode = new Node(Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), Point(botRight.longitude, botRight.latitude), MIN_WIDTH_SIZE);
            }
            if (topRightNode == NULL) {
                topRightNode = new Node(Point(topLeft.longitude + (botRight.longitude - topLeft.longitude) / 2, topLeft.latitude), Point(topLeft.longitude + (botRight.longitude - topLeft.longitude), topLeft.latitude - (topLeft.latitude - botRight.latitude) / 2), MIN_WIDTH_SIZE);
            }
            topRightNode->insert(_p, _city, _population);
        }
    }
}

bool Node::inBoundary(Point evaluate) { // Esto en base a nuestro plano de referencia, donde el 0 es el punto de al medio
    return (evaluate.longitude >= topLeft.longitude && evaluate.longitude <= botRight.longitude && evaluate.latitude <= topLeft.latitude && evaluate.latitude >= botRight.latitude);
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

long long Node::countRegion(Point _topLeftP, Point _botRightP) {
    long long count = 0;

    // Si estamos en el último nivel, revisamos si los datos que almacena cumplen con estar dentro de la distancia establecida
    if (isLeaf()) {

        // Evaluamos si el cuadrante actual está contenido por el cuadrante que buscamos
        if (_botRightP.longitude >= topLeft.longitude && botRight.longitude >= _topLeftP.longitude && _topLeftP.latitude >= botRight.latitude && topLeft.latitude >= _botRightP.latitude) {
            // Sumamos los puntos en su interior
            count += data.size();
        }
    }
    else {
        if (topLeftNode != NULL) {
            count += topLeftNode->countRegion(_topLeftP, _botRightP);
        }
        if (topRightNode != NULL) {
            count += topRightNode->countRegion(_topLeftP, _botRightP);
        }
        if (botLeftNode != NULL) {
            count += botLeftNode->countRegion(_topLeftP, _botRightP);
        }
        if (botRightNode != NULL) {
            count += botRightNode->countRegion(_topLeftP, _botRightP);
        }
    }

    return count;
}

long long Node::aggregateRegion(Point _topLeftP, Point _botRightP) {
    long long count = 0;

    // Si estamos en el último nivel, revisamos si los datos que almacena cumplen con estar dentro de la distancia establecida
    if (isLeaf()) {

        // Evaluamos si el cuadrante actual está contenido por el cuadrante que buscamos
        if (_botRightP.longitude >= topLeft.longitude && botRight.longitude >= _topLeftP.longitude && _topLeftP.latitude >= botRight.latitude && topLeft.latitude >= _botRightP.latitude) {
            // Sumamos las poblaciones guardadas en el vector
            for (int i = 0; i < data.size(); i++) {
                count += data[i].population;
            }
        }
    }
    else {
        if (topLeftNode != NULL) {
            count += topLeftNode->aggregateRegion(_topLeftP, _botRightP);
        }
        if (topRightNode != NULL) {
            count += topRightNode->aggregateRegion(_topLeftP, _botRightP);
        }
        if (botLeftNode != NULL) {
            count += botLeftNode->aggregateRegion(_topLeftP, _botRightP);
        }
        if (botRightNode != NULL) {
            count += botRightNode->aggregateRegion(_topLeftP, _botRightP);
        }
    }

    return count;
}

bool Node::isLeaf() {
    return (topLeftNode == NULL && topRightNode == NULL && botLeftNode == NULL && botRightNode == NULL);
}

void Node::print(Node* node, string indent, int branch){
    if (node != NULL) {
        cout << indent;
        if (branch == 0) {
            cout << "TL----";
            indent += "|  ";
        }
        else if (branch == 1) {
            cout << "TR----";
            indent += "|  ";
        }
        else if (branch == 2) {
            cout << "BL----";
            indent += "|  ";
        }
        else if (branch == 3) {
            cout << "BR----";
            indent += "|  ";
        }

        if (node->data.empty()) {
            cout << "X" << endl;
        }
        else {
            cout << node->data[0].city << " + " << node->data.size() - 1 << " other cities" << endl;
        }

        print(node->topLeftNode, indent, 0);
        print(node->topRightNode, indent, 1);
        print(node->botLeftNode, indent, 2);
        print(node->botRightNode, indent, 3);
    }
}

vector<Data> Node::list() {
    vector<Data> cities;
    if (isLeaf()) {
        if (!data.empty()) {
            cities.insert(cities.end(), data.begin(), data.end());
        }
    }
    else{
        vector<Data> aux;
        if (topLeftNode != NULL) {
            aux = topLeftNode->list();
            cities.insert(cities.end(), aux.begin(), aux.end());
            aux.clear();
        }
        if (topRightNode != NULL) {
            aux = topRightNode->list();
            cities.insert(cities.end(), aux.begin(), aux.end());
            aux.clear();
        }
        if (botLeftNode != NULL) {
            aux = botLeftNode->list();
            cities.insert(cities.end(), aux.begin(), aux.end());
            aux.clear();
        }
        if (botRightNode != NULL) {
            aux = botRightNode->list();
            cities.insert(cities.end(), aux.begin(), aux.end());
            aux.clear();
        }
    }

    return cities;
}
