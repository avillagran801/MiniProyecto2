#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
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
	// ---------------- IMPLEMENTACIÓN -------------------------------
	
	/*
	// cout << "How many cities do you want to insert into the QuadTree?" << endl;
	int numData;
	// cin >> numData;

	// Leemos numData líneas de la base de datos (sin contar títulos) latitude las guardamos en el vector de Data
	vector<Data> dataBase = readDataBase(numData);

	cout << "What is the width of the smallest square? (from 0.0001 to 360)" << endl;
	int width;
	cin >> width;

	// El área más pequeña será de width longitude (width/2)
	QuadTree qt(width);

	for (int i = 0; i < numData; i++) {
		qt.insert(dataBase[i].position, dataBase[i].city, dataBase[i].population);
	}

	qt.printQuadTree();
	*/

	// ------------------ EXPERIMENTACIÓN ---------------------------

	// insert()

	/*
	
	int numData;
	numData = 100000; // Cantidad de ciudades. 3.173.647; 1,6 m; 800 k; 400k; 200k; 100k
	vector<Data> dataBase = readDataBase(numData);
	double width;
	width = 22.5; // La partición más pequeña. 11,25; 22,5; 45; 90; 180; 360
	QuadTree qt(width);

	int reps = 20;
	double duration = 0;
	for (int i = 0; i < reps; i++) {

		auto start = chrono::high_resolution_clock::now();
		//####################INICIO DEL CLOCK####################
		for (int i = 0; i < numData; i++) {
			qt.insert(dataBase[i].position, dataBase[i].city, dataBase[i].population);
		}
		//#####################FIN DEL CLOCK######################
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		duration += diff.count();
	}
	duration /= reps;

	cout << "Se demoro " << duration << endl;

	*/

	// aggregateRegion() y countRegion()

	

	int numData;
	numData = 3173647; // Cantidad de ciudades. 3.173.647
	vector<Data> dataBase = readDataBase(numData);
	double width;
	width = 5.625; // La partición más pequeña. 0,703125; 1,40625; 2,8125; 5,625
	int distance = 512; // La distancia que se tendrá en cuenta. 2; 100; 128; 256; 512
	QuadTree qt(width);
	for (int i = 0; i < numData; i++) {
		qt.insert(dataBase[i].position, dataBase[i].city, dataBase[i].population);
	}

	int reps = 20;
	double duration = 0;
	for (int i = 0; i < reps; i++) {

		auto start = chrono::high_resolution_clock::now();
		//####################INICIO DEL CLOCK####################
		qt.aggregateRegion(Point(0, 0), distance);
		//#####################FIN DEL CLOCK######################
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		duration += diff.count();
	}
	duration /= reps;

	cout << "Aggregate se demoro " << duration << endl;

	duration = 0;
	for (int i = 0; i < reps; i++) {

		auto start = chrono::high_resolution_clock::now();
		//####################INICIO DEL CLOCK####################
		qt.countRegion(Point(0, 0), distance);
		//#####################FIN DEL CLOCK######################
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		duration += diff.count();
	}
	duration /= reps;

	cout << "Count se demoro " << duration << endl;

	

	return 0;
}