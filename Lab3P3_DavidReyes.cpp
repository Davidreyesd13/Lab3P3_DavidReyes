#include <iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
void menu() {
	bool resp = true;
	int opcion;
	while (resp) {
		cout << "1.Discos Duros\n2.Matriz Obstaculos\n0.Salir";
		cin >> opcion;
		switch (opcion) {
		case 1:

			break;
		case 2:

			break;
		case 0:
			resp = false;
			break;
		default:
			cout << "Opcion no valida";
		}
	}
}
int main(){
	menu();
}
