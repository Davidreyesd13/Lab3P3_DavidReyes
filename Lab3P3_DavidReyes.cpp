#include <iostream>
#include<stdlib.h>
#include<ctime>
#include <vector>
using namespace std;
int colum, fila, obstaculo;//colum -columnas,fila-filas,obstaculo-obstaculos
char** matriz{};//matriz de uso general
void menu();
void imprimirmatriz(char**);
char** rellenar_matriz(int, int);
void agregar_obstaculos(char**, int, int, int);
int posición_random(int);
int posición_random(int num) {
	
	int result = (0 + rand() % (num +1));//actualizacion del numero random
	return result;
}
void menu() {
	int opcion2=0,dato;
	int disk1[8]{}, disk2[8]{},XOR[8]{};
	bool resp = true;//variable para control del while
	int opcion;//variable de control en el switch 
	while (resp) {

		cout << "1.Discos Duros\n2.Matriz Obstaculos\n0.Salir ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			while (opcion2 != 4) {//repeticion del segundo menu
				cout << "1.Guardar datos en disco XOR\n2.Obtener datos del disco 1\n3.Obtener datos del disco 2\n4.Salir ";
				cin >> opcion2;
				//switch para segunda opcion
				switch (opcion2) {
				case 1:
					for (int i = 0; i < 8; i++) {
						cout << "Ingrese los datos del disco 1:";
						cin >> dato;//ingresar datos
						while (dato < 0 || dato > 1) {//validacion de 1 y 0
							cout << "Solo se acepta 1 y 0";
							cout << "Ingrese los datos del disco 1:";
							cin >> dato;
						}
						disk1[i] = dato;
					}
						for (int i = 0; i < 8; i++) {
							cout << "Ingrese los datos del disco 2:";
							cin >> dato;//ingresar datos
							while (dato < 0 && dato > 1) {//validacion de 1 y 0
								cout << "Solo se acepta 1 y 0";
								cout << "Ingrese los datos del disco 1:";
								cin >> dato;
							}
							disk2[i] = dato;
						}
						//rellenar el disco xor
						for (int k = 0; k < 8; k++) {
							if (disk1[k] == disk2[k]) {
								XOR[k] = 0;
							}
							else {
								XOR[k] = 1;
							}
						
						}
						cout << "XOR" << endl;//imprimir el disco xor
						for (int i = 0; i < 8; i++) {
							cout << "[" << XOR[i] << "]";
						}
						cout << endl;
						break;
				case 2:
					//impresion del disco 1 y le disco xor
					cout << "XOR" << endl;
					for (int i = 0; i < 8; i++) {
						cout << "[" << XOR[i] << "]";
					}
					cout << endl;
					cout << "Disco 1:" << endl;
					for (int i = 0; i < 8; i++) {
						cout << "[" << disk1[i] << "]";
					}
					break;
				case 3:
					//impresion del disco xor
					cout << "XOR" << endl;
					for (int i = 0; i < 8; i++) {
						cout << "[" << XOR[i] << "]";
					}
					cout << endl;
					//impresion del disco 2
					cout << "Disco 2:" << endl;
					for (int i = 0; i < 8; i++) {
						cout << "[" << disk2[i] << "]";
					}
					break;
				case 4:
					//salida
					opcion2 = 4;
					break;
				default:
					cout << "opcion no valida";
					
				}

			}
			break;
		case 2:
			cout << "Ingrese la cantidad de columnas: " << endl;
			cin >> colum;//columnas que llevara la matriz
			//valida las columnas
			while (colum < 5) {
				cout << "Ingrese la cantidad de columnas: " << endl;
				cin >> colum;
			}
			cout << "Ingrese la cantidad de Filas: " << endl;
			cin >> fila;
			//validacion de filas
			while (fila < 5) {
				cout << "Ingrese la cantidad de filas: " << endl;
				cin >> fila;
			}
			cout << "Ingrese la cantidad de obstaculos: " << endl;
			cin >> obstaculo;
			//validacion de los obstaculos 
			while (obstaculo<1 || obstaculo>colum * fila) {
				cout << "Ingrese la cantidad de obstaculos: " << endl;
				cin >> obstaculo;
			}
			//meotodos llamandose sobre metodos
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
	char** result;//variable de retorno
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
	int cont = 1;//contador para controlar el ciclo

	while (cont <= obstaculos) {
		//ciclo repetitivo para los numeros randoms
		m[posición_random(filas)][posición_random(columnas)] = '#';
		cont++;
	}
}
int main() {
	srand(time(NULL));
	menu();
}
