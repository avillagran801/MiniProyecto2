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
			int commaPos = field.find(',');
			if (commaPos != string::npos) {
				field.erase(commaPos);
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
	vector<Data> dataBase = readDataBase(10);

	for (int i = 0; i < dataBase.size(); i++) {
		cout << "Ciudad: " << dataBase[i].city << endl;
		cout << "Poblacion: " << dataBase[i].population << endl;
		cout << "Ubicacion: (" << dataBase[i].position.x << "," << dataBase[i].position.y << ")" << endl << endl;
	}

	return 0;
}