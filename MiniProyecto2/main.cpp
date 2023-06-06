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
					dataAux.position.x = stod(field);
					break;
				case 6: // Longitude
					dataAux.position.y = stod(field);
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
	cout << "How many cities do you want to insert into the QuadTree?" << endl;
	int numData;
	cin >> numData;

	// Leemos numData líneas de la base de datos (sin contar títulos) y las guardamos en el vector de Data
	vector<Data> dataBase = readDataBase(numData);

	cout << "What is the width of the smallest square? (from 0.0001 to 360)" << endl;
	int width;
	cin >> width;

	// El área más pequeña será de width x (width/2)
	QuadTree qt(width);

	for (int i = 0; i < numData; i++) {
		qt.insert(dataBase[i].position, dataBase[i].city, dataBase[i].population);
	}

	qt.printQuadTree();
	
	return 0;
}