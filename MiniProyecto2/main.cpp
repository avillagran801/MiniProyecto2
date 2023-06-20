#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "QuadTree.h"
using namespace std;

vector<Data> readDataBase(int numLines) {
	ifstream myfile("worldcitiespop_fixed.csv");
	vector<Data> dataBase;

	if (!myfile.is_open()) {
		printf("Could not open the file\n");
		return dataBase;
	}

	string line;
	getline(myfile, line); // Primera línea desechada

	for (int i = 0; i < numLines; i++) { // Limita cuántas líneas vamos a leer
		getline(myfile, line); // Guarda la línea completa del CSV

		istringstream aux(line); // Convierte el string obtenido en un stream
		
		string field;
		int currentField = 0;

		Data dataAux; // Creamos un data para agregar al vector

		while (getline(aux, field, ';')) { // Lee el string usando ";" como delimitador
			int commaPos = field.find(','); // La base de datos trae los decimales con comas, así que las convertimos en puntos
			if (commaPos != string::npos) {
				field[commaPos] = '.';
			}

			switch (currentField) {
				case 1: // City
					dataAux.city = field;
					break;
				case 4: // Population
					dataAux.population = stoi(field);
					break;
				case 5: // Latitude
					dataAux.position.latitude = stod(field);
					break;
				case 6: // Longitude
					dataAux.position.longitude = stod(field);
					break;
				default:
					break;
			}

			currentField++;
		}

		dataBase.push_back(dataAux);
	}

	return dataBase;
}

int main() {
	int numData = 100;
	vector<Data> dataBase = readDataBase(numData);
	int width = 90;

	// El área más pequeña será de width longitude
	QuadTree qt(width);

	for (int i = 0; i < dataBase.size(); i++) {
		qt.insert(dataBase[i].position, dataBase[i].city, dataBase[i].population);
	}

	cout << "Count region with p=(-85, 40) and d=1: " << qt.countRegion(Point(-85, 40), 1) << endl;

	qt.printQuadTree();
	
	return 0;
}