#include <iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int colum, fila, obstaculo;
char** matriz{};
void menu();
void imprimirmatriz(char**);
char** rellenar_matriz(int, int);
void agregar_obstaculos(char**, int, int, int);
int posición_random(int);
int posición_random(int num) {
	
	int result = (0 + rand() % (num +1));
	return result;
}
void menu() {
	bool resp = true;
	int opcion;
	while (resp) {

		cout << "1.Discos Duros\n2.Matriz Obstaculos\n0.Salir ";
		cin >> opcion;
		switch (opcion) {
		case 1:

			break;
		case 2:
			cout << "Ingrese la cantidad de columnas: " << endl;
			cin >> colum;
			while (colum < 5) {
				cout << "Ingrese la cantidad de columnas: " << endl;
				cin >> colum;
			}
			cout << "Ingrese la cantidad de Filas: " << endl;
			cin >> fila;
			while (fila < 5) {
				cout << "Ingrese la cantidad de filas: " << endl;
				cin >> fila;
			}
			cout << "Ingrese la cantidad de obstaculos: " << endl;
			cin >> obstaculo;
			while (obstaculo<1 || obstaculo>colum * fila) {
				cout << "Ingrese la cantidad de obstaculos: " << endl;
				cin >> obstaculo;
			}
			imprimirmatriz(rellenar_matriz(colum, fila));
			break;
		case 0:
			resp = false;
			break;
		default:
			cout << "Opcion no valida";
		}
	}
}
void imprimirmatriz(char** matriz) {
	for (int i = 0; i < colum; i++) {
		cout << "|";
		for (int j = 0; j < fila; j++) {
			cout << '"' << matriz[i][j] << '"' << " ";
		}
		cout << "|" << endl;
	}
}
char** rellenar_matriz(int colums, int fila) {
	char** result;
	int cont = 1;
	result = new char* [fila];
	for (int i = 0; i < fila; i++)
	{
		result[i] = new char[colums];
	}
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			result[i][j] = '-';
		}
	}
	agregar_obstaculos(result, obstaculo, colums, fila);
	return result;
}
void agregar_obstaculos(char** m, int obstaculos, int filas, int columnas) {
	int cont = 1;

	while (cont <= obstaculos) {
		
		m[posición_random(filas)][posición_random(columnas)] = '#';
		cont++;
	}
}
int main() {
	srand(time(NULL));
	menu();
}
